/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:10:47 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/11 17:53:58 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == ESC)
		exit_game(game);
	else
	{
		if (keycode == W)
			move_player(param, -1, 0);
		if (keycode == A)
			move_player(param, 0, -1);
		if (keycode == S)
			move_player(param, 1, 0);
		if (keycode == D)
			move_player(param, 0, 1);
	}
	return (0);
}

/*
instead of printing : move_player(game, Y, X)
Y&X being either -1, 0 or 1
-1 for UP and LEFT
1 for DOWN and RIGHT
W 
	move_player(game, -1, 0);
A
	move_player(game, 0, -1);
S
	move_player(game, 1, 0);
D
	move_player(game, 0, 1);
*/