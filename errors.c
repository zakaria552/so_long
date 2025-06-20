#include "so_long.h"

void exit_with_err(int code)
{
	ft_printf("Error: %s", strerror(code));
	exit(code);
}

void err_msg(char *msg, int errnum)
{
	ft_printf("Error: %s\n", msg);
	if (errnum > 0)
	{
		errno = errnum;
		perror(": ");
	}
}

void clean_exit(t_ctx *ctx, char *msg, int err_code)
{
	errno = err_code;
	if (msg)
		ft_printf("Error: %s\n", msg);
	clean_up(ctx);
	exit(errno);
}