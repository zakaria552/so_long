/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:45:11 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 14:34:13 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg(char *msg, int errnum)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_putstr_fd(msg, 2);
	if (errnum > 0)
	{
		errno = errnum;
		perror(": ");
	}
}

void	clean_exit(t_ctx *ctx, char *msg, int err_code)
{
	errno = err_code;
	ft_putstr_fd("Error\n", 2);
	if (msg)
		ft_printf("%s\n", msg);
	clean_up(ctx);
	exit(errno);
}
