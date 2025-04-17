/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:39:37 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 15:12:37 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_enemy(t_game *game)
{
	if (++game->anim_counter < 80)
		return ;//++until rhythm is 1 anim per second approx
	game->anim_counter = 0;
	game->anim_frame = (game->anim_frame + 1) % 3;
	//0 + 1 % 3 is 1 / 1 + 1 % 3 is 2 / 2 + 1 % 3 is 0
}