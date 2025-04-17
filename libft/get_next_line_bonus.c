/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:40:42 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/13 17:32:42 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_and_store(int fd, char *stock, char *buffer)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stock, buffer);
		if (!tmp)
			return (free(stock), NULL);
		free(stock);
		stock = tmp;
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if (bytes_read < 0)
	{
		free (stock);
		stock = NULL;
	}
	return (stock);
}

char	*extract_line(char **stock, char *tmp)
{
	char	*newline_pos;
	char	*line;

	newline_pos = ft_strchr(*stock, '\n');
	if (newline_pos)
	{
		line = malloc((newline_pos - *stock) + 2);
		if (!line)
			return (free(*stock), NULL);
		ft_strlcpy(line, *stock, (newline_pos - *stock) + 2);
		tmp = ft_strdup(newline_pos + 1);
		if (!tmp)
			return (free(line), free(*stock), NULL);
		free(*stock);
		*stock = tmp;
	}
	else
	{
		line = ft_strdup(*stock);
		if (!line)
			return (free(*stock), NULL);
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stock[fd])
	{
		stock[fd] = ft_strdup("");
		if (!stock[fd])
			return (free(stock[fd]), NULL);
	}
	stock[fd] = read_and_store(fd, stock[fd], buffer);
	free(buffer);
	if (!stock[fd])
		return (NULL);
	if (*stock[fd] == '\0')
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	line = extract_line(&stock[fd], "");
	return (line);
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	int		i = 1;
// 	char	*line;

// 	while (i < argc)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("Fucked up\n");
// 			return (1);
// 		}
// 		printf("\nBegoth, the %ith file:\n", i);
// 		int	l = 0;
// 		while (l < 10)
// 		{
// 			line = get_next_line(fd);
// 			printf("%s", line);
// 			l++;
// 		}
// 		i++;
// 	}
// 	close (fd);
// 	return (0);
// }