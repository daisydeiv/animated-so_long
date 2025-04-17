/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:32:08 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/09 11:20:50 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
// {
//     void	*mlx;
//     void	*win;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

//     mlx = mlx_init(); // Initialisation de la MinilibX
//     win = mlx_new_window(mlx, 1080, 720, "Solong Window"); // Création d'une fenêtre de 800x600
// 	img = mlx_xpm_file_to_image(mlx, "texture_test.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);//put at coord X&Y

//     mlx_loop(mlx); // Boucle principale de l'application

//     return (0);
// }



/*

gcc so_long.c -L./mini_libx -lmlx -lX11 -lXext -lm -o solong
how to execute the project?
	=> ./so_long maps/map.ber


notes for the project :
the maps are in .ber format
the sprites are in .xpm format
rendering:
	- you have to draw each layer at each iteration (move)
	- background > statics > player
key handling:
	- update the P position according to its pixel coordinates X & Y
	- ex: arrow_right = player.pos.x = +1;
	- 2ex: arrow_down = player.pos.y = +1;
	/!\ don't forget that walls (1) are not walkable, so update X&Y only if move available

steps :
	map_parsing (open with GNL)
		- does the file exist?
		- does it only include 1s, 0s, Cs, P (1) and E (1)?
			=> any other char = invalid map;
		- is it borded by 1s?
		- is the map a rectangle? (same numbers of char in every lines)
		- only one E? + is it accessible?
		-> parallelly, are all the Cs accessible? (and is there at least one?)
		exitable
			-> C and E counter
			parse the map
				-> if not same count of C as the first steps of parsing, not good
				-> if E is 0, not good
			or you can bactrack from E to S and all the Cs to S, like I do with mazes
			but it's a backtracking algorythm, so new concept, might be complicated
	gaming
		- use a window with miniLibX
		- load all .xpm images and stock them in the memory
		- hooks, or how to play a game
			- key_handlers (WASD + ESC)
			- click on the cross it quits (so mouse?)
	coordinates :
		- always check if the new position is a wall before updating player_pos
			-> if it's a wall, do not move, do not count it as a move either?
			+> check if outside the map, just to be sure??? (but surrendered by walls)
		- if it's a C, update the C counter
			+ update map so it's a 0 not a C (empty tile)
			-> if all C, open/unlock E
				=> do two images for E; one closed, one open??


	images are to be a struct declaring void *(name) for each type
	ex: void	*wall
	also include int for img width and height
		=> which will serve for the mlx_xpm_to_file function
			that find them itself with ("file.xpm", &width, &height)

	game is also a struct
		first are void *mlx and void *win 
		then the char **map of a read_map
		int height and width, again, but for the screen (and the mlx functions)
		call a t_image img (to do like game->img.smthg)
		and t_pos for each elem (player, exit, maybe Cs?, ennemies if I add them)

	and as I wanted, a struct t_pos to declare x and y
		the coordinates

	IMPORTANT
		do NOT forget to clean the map if errors or/and when exit
		do NOT forget to init images to NULL as they are supposed to be files, so ints, so NULL
		you'll need a count_height and count_width functions to declare 
			game->height and game->width (for the void	*win)

	file exit.c that deals with wether you can or cannot exit, depending on the Cs
		-recall count_elems for C
		-should I use an int collect inside the t_game to keep count?
		-> like, every time Player is on a C, I do game->collect++
		-> if game->collect = count_elems(game, 'C'), then Exit is good
		-> make E act like a 0 until you have all the Cs
		so,
		if (game->collect == count_elems(game, 'C'))
			close_game(game); (but with exit success);
		else
			ignore?
		enemies :
		else if (game->player == game->enemy) //player.row&&.col == enemy.row&&.col
			close_game(game); (but with failure)

		I should maybe have a close_game (for technical issues) and an exit_game (for failure or success)

	file positions.c
	=> t_pos return two informations : Y and X, the coordinates
		- t_pos	find_position(game, type)
		- init position to -1 and -1, just to be sure
		- trace map until (game->map[y][x] == type)
		- update position.y and position.x
		- return position

	file player.c //to deal with movements
		- move_player(game, y_move, x_move)
		- int new_y and int new_x
		- new_y = game->player.row + y_move
		- same with x
		- but only if not 1?
		- here, check every win/fail conditions?

	game->moves
		should be ++ only if the move was okay
			(ft_printf + inside the game too (for bonuses))
		so, inside move_player?
		with a condition like....
		
	Theory for collectibles :
	inside t_game, declare an int c
	go back to check_elems,
		-> game->c = count_elem(game, 'C')
		-> still check all the same, alright
	now, while gaming, if game->player (pos) == C
		-> game->c--
		-> and C becomes a 0, also, no forgetty
	when and only when game->c == 0 can I open the Exit
*/


// void load_sprites(t_game *game)
// {
//     game->cat_frame[0] = mlx_xpm_file_to_image(game->mlx, "./cat_sprites/cat_left1.xpm", &width, &height);
//     game->cat_frame[1] = mlx_xpm_file_to_image(game->mlx, "./cat_sprites/cat_left2.xpm", &width, &height);
//     game->cat_frame[2] = mlx_xpm_file_to_image(game->mlx, "./cat_sprites/cat_left3.xpm", &width, &height);
//     game->cat_frame[3] = mlx_xpm_file_to_image(game->mlx, "./cat_sprites/cat_left4.xpm", &width, &height);
// }

// int animate_cat(t_game *game) 
// {
//     static int frame = 0;
//     mlx_put_image_to_window(game->mlx, game->win, game->cat_frame[frame], x, y);
//     frame = (frame + 1) % 4;
//     return (0);
// }

// in the main :
	// mlx_loop_hook(game->mlx, animate_cat, game);

