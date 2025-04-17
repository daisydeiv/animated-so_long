/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:02:22 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 15:27:05 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_elem(t_game *game, char elem, int y, int count)//char or int? same difference, right?
{
	int	x;

	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == elem)
			{
				count++;
				if (elem == 'P')
				{
					game->player.y = y;
					game->player.x = x;
				}
				if (elem == 'E')
				{
					game->exit.y = y;
					game->exit.x = x;
				}
			}
		}
	}
	return (count);
}

int	check_elems(t_game *game)
{
	int	p;
	int	e;
	// int	x;

	p = count_elem(game, 'P', -1, 0);
	e = count_elem(game, 'E', -1, 0);
	game->nb_collect = count_elem(game, 'C', -1, 0);
	// x = count_elem(game, 'X');
	if (p != 1 || e != 1 || !game->nb_collect)// || x > 1)
		return (false);//something fucked up
	return (true);//all is good!
}

// int	check_size(t_game *game)
// {
// 	if ((game->height * TILESET) > 720 || (game->width * TILESET) > 1080)
// 	//should I round down? 1000x700??
// 		return (false);//too big
// 	return (true);
// }

void	error_map_exit(t_game *game, char *message)//close?
{
	ft_printf("Error: %s\n", message);
	close_map(game);
}

bool	valid_map(t_game *game)
{
	if (!check_rectangular(game))
		return (error_map_exit(game, "map is not rectangular"), false);
	if (!check_frame(game))
		return (error_map_exit(game, "missing walls!"), false);
	if (!check_chars(game))
		return (error_map_exit(game, "intruders, intrudeeers!!"), false);
	if (!check_elems(game))
		return (error_map_exit(game, "nah, brother, things are amiss"), false);
	// if (!check_size(game))
	// 	return (error_map_exit(game, "map might exceeds screen limits"), false);
	// if (!check_map(game))
	// 	return (error_map_exit(game, "pigeon can't go home"), false);//deleted
	return (true);//should not even return anything actually
}
