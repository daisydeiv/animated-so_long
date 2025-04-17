/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:47:18 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:41:58 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// main function and its utils

void	print_inside_game(t_game *game)
{
	char	*number;
	char	*print;
	size_t	total_length;

	number = ft_itoa(game->moves);
	total_length = ft_strlen("moves : ") + ft_strlen(number) + 1;
	print = malloc(total_length);//apparently a ft_calloc(sizeof(char)) would be safer
	//+ free(number) if it didn't work
	if (print)
	{
		ft_strcpy(print, "moves : ");
		ft_strcat(print, number);
		mlx_string_put(game->mlx, game->win, 15, 20, 0xFFFFFF, print);
		free(print);
	}
	free(number);//actually very interesting to not forget about freeing itoa
}

int	game_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	animate_enemy(game);
	load_map(game, -1, -1);
	print_inside_game(game);
	return (0);//needs to be an in for the mlx
}//added

int	main(int ac, char *av[])
{
	// av[1] = "./maps/map.ber";
	// ac = 2;

	t_game	game;

	if (ac != 2)
		return (1);
	ft_memset(&game, 0, sizeof(t_game));
	init_game(&game, av[1]);
	if (!check_map(&game))//added
		close_game(&game, 'P');//added
	load_map(&game, -1, -1);//load at every move
	mlx_key_hook(game.win, key_handler, &game);//key handling
	mlx_hook(game.win, 17, 0, exit_game, &game);//click exit//close_game(game, "esc");
	mlx_loop_hook(game.mlx, game_loop, &game);//added
	mlx_loop(game.mlx);
	return (0);
}

// problem : loads back every time, so the moves counter inside the game disappear at some points
//problem solved by adding the print loop inside the game_loop
//alternative problem : the game jumps? loading is weird