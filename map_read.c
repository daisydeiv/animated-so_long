/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:00:08 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/13 17:09:21 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_lines(char **map, int i, int fd)
{
	while (i >= 0)
		free(map[i--]);
	free(map);
	close (fd);
}

char	**read_map(char *fileber)
{
	int		fd;
	char	**map;
	int		i;
	int		height;

	// if (!check_file_format(fileber))
	// return ("[Error:] invalide file format\n", EXIT_FAILURE);
	height = get_map_height(fileber);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(fileber, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);//mine
		if (!map[i])
			free_lines(map, i, fd);
		i++;
	}
	map[height] = NULL;//always finish the tabtab
	close(fd);
	return (map);
}
