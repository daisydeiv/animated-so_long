/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:00:04 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 15:58:21 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	green_squaring(t_game *game, int y, int x)
{
	usleep(50000);
	mlx_put_image_to_window(game->mlx, game->win, game->img.green,
		(x * TILESET), (y * TILESET));
}

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
			green_squaring(game, y, x);
			return (0);
		}
		i++;
	}
	return (0);
}

bool	walkable(char c)
{
	if (c == '1' || c == 'X')
		return (false);
	return (true);
}

void	dfs(t_game *game, int tab[100][2], int y, int x)
{
	if (game->map[y][x] == 'C')
		game->dfs_collect++;
	if (game->map[y][x] == 'P')
		game->dfs_player++;
	if (walkable(game->map[y][x - 1]) && !in_tab(tab, y, x - 1, game))//left __ && != 'X'??
		dfs(game, tab, y, x - 1);
	if (walkable(game->map[y - 1][x]) && !in_tab(tab, y - 1, x, game))//up
		dfs(game, tab, y - 1, x);
	if (walkable(game->map[y][x + 1]) && !in_tab(tab, y, x + 1, game))//right
		dfs(game, tab, y, x + 1);
	if (walkable(game->map[y + 1][x]) && !in_tab(tab, y + 1, x, game))//down
		dfs(game, tab, y + 1, x);
}

bool	check_map(t_game *game)
{
	int	tab[1000][2];

	ft_memset(tab, 0, sizeof(tab));
	game->dfs_collect = 0;
	game->dfs_player = 0;
	tab[0][0] = game->exit.y;
	tab[0][1] = game->exit.x;
	load_map(game, -1, -1);
	dfs(game, tab, game->exit.y, game->exit.x);
	if (game->dfs_player == 1 && game->dfs_collect == game->nb_collect)
		return (true);
	return (false);
}
