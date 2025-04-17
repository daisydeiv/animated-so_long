/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:33:20 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:25:58 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_txrs(t_game *game)
{
	game->img.empty = NULL;
	game->img.wall = NULL;
	game->img.player = NULL;
	game->img.exit = NULL;
	game->img.collect = NULL;
	game->img.enemy = NULL;
	game->img.green = NULL;
	game->img.height = 0;
	game->img.width = 0;
	game->ghost[0] = NULL;//added
	game->ghost[1] = NULL;//added
	game->ghost[2] = NULL;//added
	game->anim_counter = 0;//added or map_load?
	game->anim_frame = 0;//added or map_load?
}

void	init_txrs(t_game *game)
{
	create_txrs(game);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, "./textures/empty.xpm",
		&game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
		&game->img.width, &game->img.height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
		&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
		&game->img.width, &game->img.height);
	game->img.collect = mlx_xpm_file_to_image(game->mlx, "./textures/collect.xpm",
		&game->img.width, &game->img.height);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm",
		&game->img.width, &game->img.height);
	game->img.green = mlx_xpm_file_to_image(game->mlx, "./textures/green.xpm",
		&game->img.width, &game->img.height);//added
	game->ghost[0] = mlx_xpm_file_to_image(game->mlx, "./textures/ghost0.xpm",
		&game->img.width, &game->img.height);//added
	game->ghost[1] = mlx_xpm_file_to_image(game->mlx, "./textures/ghost1.xpm",
		&game->img.width, &game->img.height);//added
	game->ghost[2] = mlx_xpm_file_to_image(game->mlx, "./textures/ghost2.xpm",
		&game->img.width, &game->img.height);//added
}

void	destroy_txrs(t_game *game)
{
	if (game->img.empty)
		mlx_destroy_image(game->mlx, game->img.empty);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.collect)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.enemy)
		mlx_destroy_image(game->mlx, game->img.enemy);
	if (game->img.green)//added
		mlx_destroy_image(game->mlx, game->img.green);//added
	if (game->ghost[0])
		mlx_destroy_image(game->mlx, game->ghost[0]);//added
	if (game->ghost[1])
		mlx_destroy_image(game->mlx, game->ghost[1]);//added
	if (game->ghost[2])
		mlx_destroy_image(game->mlx, game->ghost[2]);//added
}
