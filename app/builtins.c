#include "builtins.h"

bool change_directory(const char *name, struct status *s)
{
  if (string_equal(name, ""))
  {
    return true;
  }

  if (string_equal(name, "."))
  {
    return true;
  }

  if (string_equal(name, ".."))
  { // go back by one directory
    int i = string_length(s->working_directory) - 1;
    while (s->working_directory[i] != '/')
    {
      i--;
    }
    if (i == 0)
    { // working directory is root or 1 depth
      free(s->working_directory);
      s->working_directory = string_copy("/");
    }
    else
    {
      s->working_directory[i] = '\0';
    }
    return true;
  }

  if (string_equal(name, "~"))
  {
    free(s->working_directory);
    s->working_directory = string_copy(getenv("HOME"));
    return true;
  }

  char *aux;
  if (s->working_directory[1] != '\0')
  { // Only if working dir != "/"
    aux = string_concat(s->working_directory, "/");
  }
  else
  {
    aux = string_copy("/");
  }

  char *full_path = string_concat(aux, name);
  free(aux);
  aux = NULL;

  if (directory_exists(full_path))
  {
    free(s->working_directory);
    s->working_directory = full_path;
    return true;
  }
  free(full_path);
  full_path = NULL;
  return false;
}

bool handle_builtins(char *command, struct status *s) {
  char **args = string_split(command, ' ');

  if (string_equal(args[0], "exit"))
  {
    free_string_array(args);
    free(s->working_directory);
    free(s);
    exit(0);
  }
  if (string_equal(args[0], "echo"))
  {
    print_string(command, 5);
    printf("\n");
    goto success;
  }
  if (string_equal(args[0], "type"))
  {
    // Builtins
    const char *builtins[] = {"exit", "echo", "type", "pwd", "cd"};
    for (int i = 0; i < 5; i++)
    {
      if (string_equal(args[1], builtins[i]))
      {
        printf("%s is a shell builtin\n", args[1]);
        goto success;
      }
    }

    // Path
    char *path = get_file_path(args[1]);
    if (path != NULL)
    {
      printf("%s is %s%s\n", args[1], path, args[1]);
      free(path);
      path = NULL;
      goto success;
    }

    printf("%s: not found\n", args[1]);
    goto success;
  }
  if (string_equal(args[0], "pwd"))
  {
    printf("%s\n", s->working_directory);
    goto success;
  }
  if (string_equal(args[0], "cd"))
  {
    // No args
    if (args[1] == NULL)
    {
      printf("cd: No directory\n");
      goto success;
    }

    // Absolute path
    if (args[1][0] == '/')
    {
      if (directory_exists(args[1]))
      {
        free(s->working_directory);
        s->working_directory = string_copy(args[1]);
        goto success;
      }
      printf("cd: %s: No such file or directory\n", args[1]);
      goto success;
    }

    // Relative path
    if (args[1][0] == '.' || args[1][0] == '~')
    {
      char **movement = string_split(args[1], '/');
      // Store the old working directory in case the path is invalid
      char *old_wd = string_copy(s->working_directory);

      int i = 0;
      while (movement[i] != NULL)
      {
        if (!change_directory(movement[i], s))
        { // If the path is invalid, cancel everything
          printf("cd: %s: No such file or directory\n", string_copy(args[1]));
          free(s->working_directory);
          s->working_directory = old_wd;

          free_string_array(movement);
          goto success;
        }
        i++;
      }
      free_string_array(movement);
      free(old_wd);
      goto success;
    }

    goto success;
  }

  return false;

success:
  free_string_array(args);
  return true;
}
