#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdbool.h>
#include "status.h"
#include "file.h"
#include "str.h"

/** if the provided path is valid, change the working directory and return true;
 * else return false */
bool change_directory(const char *path, struct status *s);

/** if the given command is a builtin, handle it and return true,
 * else return false */
bool handle_builtins(char *command, struct status *s);

#endif
