#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "so_types.h"
// parser
t_map *parse_map(char *name);

// map validator
bool validate_map(char *fname, char *map);

// errors
void exit_with_err(int code);
void err_msg(char *msg, int errnum);

// io_utils
char *read_from_file(char *name);

#endif
