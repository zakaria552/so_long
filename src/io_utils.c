/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:46:51 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 14:46:52 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_from_file(char *name)
{
	char	*txt;
	char	buff[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		fd;

	fd = open(name, O_RDONLY);
	txt = "";
	if (fd < 0)
		return (NULL);
	ft_memset(buff, 0, BUFFER_SIZE);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		txt = ft_strjoin(buff, txt);
		if (!txt)
		{
			close(fd);
			free(txt);
			return (NULL);
		}
		ft_memset(buff, 0, BUFFER_SIZE);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	close(fd);
	return (txt);
}

char	*read_from_file2(char *name)
{
	char	*buff;
	char	*tmp;
	char	*line;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buff = get_next_line(fd);
	if (!buff)
	{
		close(fd);
		return (NULL);
	}
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = buff;
		buff = ft_strjoin(buff, line);
		if (!buff)
		{
			free(tmp);
			free(line);
			break ;
		}
		free(tmp);
		free(line);
	}
	close(fd);
	return (buff);
}
