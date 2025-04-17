/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:25:08 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:42:18 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_game(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->map = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	game->nb_collect = 0;
	game->dfs_collect = 0;
	game->dfs_exit = 0;
	game->player.y = 0;
	game->player.x = 0;
	game->nothing = 0;//added for parsing
}

void	init_game(t_game *game, char *fileber)
{
	create_game(game);
	game->height = get_map_height(fileber);
	game->map = read_map(fileber);
	game->width = get_map_width(game->map);
	if (!valid_map(game))
		return ;//it's in the errors checking
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, ((game->width) * TILESET),
		((game->height) * TILESET), "I'm doing my best, don't be mean");
	init_txrs(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->img.empty, -1, -1);//put at coord X&Y
}

void	load_map(t_game *game, int y, int x)
{
	while (++y < game->height)
	{
		x = -1;
		while (game->map[y][++x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img.empty,
					(x * TILESET), (y * TILESET));
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
					(x * TILESET), (y * TILESET));
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
					(x * TILESET), (y * TILESET));
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.collect,
					(x * TILESET), (y * TILESET));
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img.player,
					(x * TILESET), (y * TILESET));
			// else if (game->map[y][x] == 'X')
			// 	mlx_put_image_to_window(game->mlx, game->win, game->img.enemy,
			// 		(x * TILESET), (y * TILESET));
			else if (game->map[y][x] == 'X')//replacement
				mlx_put_image_to_window(game->mlx, game->win, 
					game->ghost[game->anim_frame], (x * TILESET), (y * TILESET));//added
		}
	}
}
