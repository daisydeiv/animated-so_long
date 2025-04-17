/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:24:00 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:42:08 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_inside_game(t_game *game)
// {
// 	char	*number;
// 	char	*print;
// 	size_t	total_length;

// 	number = ft_itoa(game->moves);
// 	total_length = ft_strlen("moves : ") + ft_strlen(number) + 1;
// 	print = malloc(total_length);//apparently a ft_calloc(sizeof(char)) would be safer
// 	// + free(number) if it didn't work
// 	if (print)
// 	{
// 		ft_strcpy(print, "moves : ");
// 		ft_strcat(print, number);
// 		mlx_string_put(game->mlx, game->win, 15, 20, 0xFFFFFF, print);
// 		free(print);
// 	}
// 	free(number);//actually very interesting to not forget about freeing itoa
// }

void	move_player(t_game *game, int y, int x)
{
	int	new_y;
	int	new_x;

	new_y = game->player.y + y;
	new_x = game->player.x + x;
	if (game->map[new_y][new_x] == 'E' && !game->nb_collect)
		close_game(game, 'W');
	if (game->map[new_y][new_x] == 'X')
		close_game(game, 'F');
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->nb_collect--;
	game->map[game->player.y][game->player.x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player.y += y;
	game->player.x += x;
	ft_printf("moves : %d\n", ++game->moves);
	load_map(game, -1, -1);
	print_inside_game(game);
}

// ###############################################################################

//with the animated enemy, the counter disappears coz I have to reload the map every time
//problem resolved, but loading/rendering is shitty