/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:00:59 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/15 14:50:18 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	return (width);
}

int	get_map_height(char *fileber)
{
	int		fd;
	int		heigth;
	char	*line;

	heigth = 0;
	fd = open(fileber, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);//mine
	while (line)
	{
		free(line);
		heigth++;
		line = get_next_line(fd);//mine
	}
	close(fd);
	return (heigth);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

char	*ft_strcat(char *dst, char *src)
{
	char	*ptr;

	ptr = dst;
	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dst);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

