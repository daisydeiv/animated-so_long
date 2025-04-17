/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:39:11 by mle-brie          #+#    #+#             */
/*   Updated: 2025/04/17 11:14:13 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mini_libx/mlx.h"
# include "mini_libx/mlx_int.h"
# include <stdbit.h>
# define TILESET 64//64x64 pixels per tile
# define ESC 65307//Linux code for ESC key
# define W 119//up
# define A 97//left
# define S 115//down
# define D 100//right

/*
keycodes :
ESC == 53//27
W == 13//119
A == 0//97
S == 1//115
D == 2//100
*/

// struct decl here
typedef struct s_position//y as rows, x as columns ; position of an element
{
	int	y;//nammed row to be more understandable??
	int	x;//nammed col to be more understandable??
}	t_pos;

typedef struct s_texture//ints are automatic ; don't forget to innit to NULL
{
	void	*empty;//0
	void	*wall;//1, frame
	void	*player;//P, only one
	void	*exit;//E, only one, accessible
	void	*collect;//C, at least one, accessible
	void	*enemy;//X, maybe?
	void	*green;
	int		height;
	int		width;
}	t_txr;

typedef struct s_game//mlx and win ; **map has to be set with read_map ; ints auto? ; game->img.smthg
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		nb_collect;
	int		dfs_collect;
	int		dfs_exit;
	t_txr	img;
	t_pos	player;
	// t_pos	exit;
	// t_pos	enemy;
	int		moves;
	// void	*cat_frame[4];
	int		anim_counter;//added
	void	*ghost[3];//added
	int		anim_frame;//added
	int		nothing;//added for parsing check
}	t_game;

// functions here
// map_things
char	**read_map(char *fileber);
int		get_map_height(char *fileber);
int		get_map_width(char	**map);
void	init_game(t_game *game, char *fileber);
void	dfs(t_game *game, int tab[100][2], int y, int x);
bool	check_map(t_game *game);

// errors things
bool	valid_map(t_game *game);
int		check_rectangular(t_game *game);
int		check_frame(t_game *game);
int		check_chars(t_game *game);
int		count_elem(t_game *game, char elem);
int		check_elems(t_game *game);
// int		check_size(t_game *game);
// int		check_file_format(char *file);

// texture things
void	init_txrs(t_game *game);
void	load_map(t_game *game, int y, int x);

// keys and hooks things
int		key_handler(int keycode, void *param);

// closing things
void	free_map(char **map);
void	destroy_txrs(t_game *game);
int		close_game(t_game *game, char type);
int		exit_game(t_game *game);
void	error_map_exit(t_game *game, char *message);
void	close_map(t_game *game);

// player/move things
void	move_player(t_game *game, int y, int x);
void	print_inside_game(t_game *game);
void	animate_enemy(t_game *game);//added

// utils/move to libft afterhand, thanks
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *dst, char *src);

#endif