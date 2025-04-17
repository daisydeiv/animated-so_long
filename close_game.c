/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:04:09 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/16 16:20:59 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game, char type)
{
	if (!game)
		return (0);
	free_map(game->map);
	destroy_txrs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (type == 'P')//added
	{
		ft_printf("Pigeon can't go home\n");
		exit(EXIT_FAILURE);
	}//added
	else if (type == 'F')
	{
		ft_printf("You failed, want to try again?\n");
		exit(EXIT_FAILURE);
	}
	else if (type == 'W')
		ft_printf("Congrats, you've won!!\n");
	exit(EXIT_SUCCESS);
}

int	exit_game(t_game *game)
{
	if (!game)
		return (0);
	free_map(game->map);
	destroy_txrs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	if (game->mlx)
		free(game->mlx);
	ft_printf("Leaving so soon, beautiful?\n");
	exit(EXIT_SUCCESS);
}

void	close_map(t_game *game)
{
	free_map(game->map);
	ft_printf("map has been cleaned out of existence\n");
	exit(EXIT_FAILURE);
}

//check memory leaks, babe

/*
destroy_window : destroy an individual opened window
destroy_display : necessary to avoid leaks on Linux, linked to the mlx_init() function
free the potentially remaining mlx memory

Remember : if you've malloced anything, you have to free it (map)
textures take place, so clean them before destroying everything
Check that you're not double-freeing shit, please

For now, keep the exit(0), check if necessary after  you've done everything else??
*/