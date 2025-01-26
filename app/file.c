#include "file.h"

char *get_file_path(const char *file_name)
{
  char **path = string_split(getenv("PATH"), ':');
  int i = 0;
  char *result = NULL;
  while (path[i] != NULL && result == NULL)
  {
    DIR *d;
    struct dirent *dir;
    d = opendir(path[i]);
    if (d)
    {
      while ((dir = readdir(d)) != NULL)
      {
        if (string_equal(dir->d_name, ".") || string_equal(dir->d_name, ".."))
          continue;
        if (string_equal(dir->d_name, file_name))
        {
          result = string_concat(path[i], "/");
          break;
        }
      }
      closedir(d);
    }
    i++;
  }
  free_string_array(path);

  return result;
}

bool directory_exists(const char *path)
{
  DIR *d = opendir(path);
  if (d)
  {
    closedir(d);
    return true;
  }
  return false;
}