#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "str.h"
#include "math.h"
#include "file.h"
#include "status.h"
#include "builtins.h"

void handle_command(char *command);

int main();
#endif
