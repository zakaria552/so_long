/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:31:00 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 18:31:09 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_from_file(char *name)
{
	char		*buff;
	char		*tmp;
	char		*line;
	const int	fd = open(name, O_RDONLY);

	if (fd < 0)
		return (NULL);
	buff = get_next_line(fd);
	while (buff)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = buff;
		buff = ft_strjoin(buff, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (buff);
}
