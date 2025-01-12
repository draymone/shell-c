#ifndef MAIN_C_H
#define MAIN_C_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "str.h"
#include "math.h"
#include "file.h"

struct status {
  char *working_directory;
  };


/** if the provided path is valid, change the working directory and return true;
* else return false */
bool change_directory(const char *path, struct status *s);

void handle_command(char *command, struct status *status);

int main();
#endif
