#include "so_long.h"

void exit_with_err(int code)
{
	ft_printf("Error: %s", strerror(code));
	exit(code);
}

void err_msg(char *msg, int errnum)
{
	ft_printf("Error: %s", msg);
	if (errnum > 0)
	{
		errno = errnum;
		perror(": ");
	}
}