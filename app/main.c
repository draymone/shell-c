#include "main.h"

struct status *s;

void handle_command(char *command)
{
  strip(command, 1); // Removes the trailing newline

  // Builtins
  if (handle_builtins(command, s)) return;

  // Programs
  char **args = string_split(command, ' ');
  char *path = get_file_path(args[0]);
  if (path != NULL)
  {
    char *program = string_concat(path, command);
    system(program);
    free(program);
    free(path);
    goto free_memory;
  }

  printf("%s: command not found\n", args[0]);

free_memory:
  free_string_array(args);
}

int main()
{
  // Init status
  s = memory_alloc(sizeof(struct status));
  s->working_directory = string_copy("/app");

  while (1)
  {
    // Flush after every printf
    setbuf(stdout, NULL);
    // Prompt
    printf("$ ");

    // Wait for user input
    char input[100];
    if (fgets(input, 100, stdin) == NULL) continue;

    handle_command(input);
  }
  return 0;
}
