#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include "str.h"

/** returns the path of the first file in path having the desired name, with trailing /,
 * NULL if none was found */
char *get_file_path(const char *file_name);

/** returns true if the specified directory exists, false otherwise */
bool directory_exists(const char *path);

#endif
