#include "so_long.h"

char *read_from_file(char *name)
{
	char *txt;
	char buff[BUFFER_SIZE];
	ssize_t bytes_read;
	int fd;

	fd = open(name, O_RDONLY);
	txt = "";
	if (fd < 0)
		return NULL;
	ft_memset(buff, 0, BUFFER_SIZE);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		txt = ft_strjoin(buff, txt);
		if (!txt)
		{
			close(fd);
			free(txt);
			return NULL;
		}
		ft_memset(buff, 0, BUFFER_SIZE);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	close(fd);
	return (txt);
}
