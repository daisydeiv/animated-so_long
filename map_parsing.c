/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:00:04 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:27:00 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	green_squaring(t_game *game, int y, int x)
// {
// 	mlx_put_image_to_window(game->mlx, game->win, game->img.green,
// 		(x * TILESET), (y * TILESET));

// 	// if (game->img.green)
// 	// 	mlx_destroy_image(game->mlx, game->img.green);
// }

int	in_tab(int tab[100][2], int y, int x, t_game *game)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (tab[i][0] == y && tab[i][1] == x)
			return (1);
		else if (tab[i][0] == 0 && tab[i][1] == 0)
		{
			tab[i][0] = y;
			tab[i][1] = x;
			// green_squaring(game, y, x);
			game->nothing++;//added, don't care
			return (0);
		}
		i++;
	}
	return (0);
}

void	dfs(t_game *game, int tab[100][2], int y, int x)
{
	if (game->map[y][x] == 'C')
		game->dfs_collect++;
	if (game->map[y][x] == 'E')
		game->dfs_exit++;
	if (game->map[y][x - 1] != '1' && !in_tab(tab, y, x - 1, game))//left __ && != 'X'??
	{
		dfs(game, tab, y, x - 1);
		// ft_printf("row %d col %d got left\n", y, x);
	}
	if (game->map[y - 1][x] != '1' && !in_tab(tab, y - 1, x, game))//up
	{
		dfs(game, tab, y - 1, x);
		// ft_printf("row %d col %d got up\n", y, x);
	}
	if (game->map[y][x + 1] != '1' && !in_tab(tab, y, x + 1, game))//right
	{
		dfs(game, tab, y, x + 1);
		// ft_printf("row %d col %d got right\n", y, x);
	}
	if (game->map[y + 1][x] != '1' && !in_tab(tab, y + 1, x, game))//down
	{
		dfs(game, tab, y + 1, x);
		// ft_printf("row %d col %d got down\n", y, x);
	}
}

bool	check_map(t_game *game)
{
	int	tab[1000][2];

	ft_memset(tab, 0, sizeof(tab));
	game->dfs_collect = 0;
	game->dfs_exit = 0;
	dfs(game, tab, game->player.y, game->player.x);
	if (game->dfs_exit == 1 && game->dfs_collect == game->nb_collect)
		return (true);
	return (false);
}
