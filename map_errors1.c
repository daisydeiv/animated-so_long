/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:01:33 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/11 16:49:02 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_file_format(char *file)
// {
// 	int	len;

// 	len = ft_strlen(file);
// 	if (len >= 4 && (ft_strncmp(file + (len - 4), ".ber", 4) == 0))
// 		return (true);
// 	return (false);
// }

int	check_rectangular(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
			x++;
		if (x != game->width)
			return (false);//one line is not the good size
		y++;
	}
	return (true);//map is rectangular
}

int	check_frame(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if ((y == 0 || y == (game->height - 1))//height is still 8 so pos needs to be 7
				|| (x == 0 || x == (game->width - 1)))//width - 1??????
			{
				if (game->map[y][x] != '1')
					return (false);//not a wall
			}
			x++;
		}
		y++;
	}
	return (true);//the map if framed how it should
}

bool	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'X')
		return (true);
	return (false);
}

int	check_chars(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && x < game->width - 1)
		{
			if (!(valid_char(game->map[y][x])))
				return (false);// fucked up char	
			x++;
		}
		y++;
	}
	return (true);
}
