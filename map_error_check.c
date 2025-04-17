// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   map_error_check.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mle-brie <mle-brie@student.42perpignan.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/29 16:13:15 by mle-brie          #+#    #+#             */
// /*   Updated: 2025/04/15 14:51:05 by mle-brie         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// // int	check_file_format(char *file)
// // {
// // 	int	len;

// // 	len = ft_strlen(file);
// // 	if (len >= 4 && (ft_strncmp(file + (len - 4), ".ber", 4) == 0))
// // 		return (true);
// // 	return (false);
// // }

// int	check_rectangular(t_game *game)//errors 1
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while(y < game->height)
// 	{
// 		x = 0;
// 		while (game->map[y][x] && game->map[y][x] != '\n')
// 			x++;
// 		if (x != game->width)
// 			return (false);//one line is not the good size
// 		y++;
// 	}
// 	return (true);//map is rectangular
// }

// int	check_frame(t_game *game)//errors 1
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while(y < game->height)
// 	{
// 		x = 0;
// 		while (game->map[y][x] && game->map[y][x] != '\n')
// 		{
// 			if ((y == 0 || y == (game->height - 1))//height is still 8 so pos needs to be 7
// 				|| (x == 0 || x == (game->width - 1)))//width - 1??????
// 			{
// 				if (game->map[y][x] != '1')
// 					return (false);//not a wall
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (true);//the map if framed how it should
// }

// bool	valid_char(char c)//errors 1
// {
// 	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'X')
// 		return (true);
// 	return (false);
// }

// int	check_chars(t_game *game)//errors 1
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (game->map[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x] && x < game->width - 1)
// 		{
// 			if (!(valid_char(game->map[y][x])))
// 				return (false);// fucked up char	
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (true);
// }

// int	count_elem(t_game *game, char elem)//char or int? same difference, right?//errors 2
// {
// 	int	y;
// 	int	x;
// 	int	count;

// 	y = 0;
// 	count = 0;
// 	while (game->map[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x])
// 		{
// 			if (game->map[y][x] == elem)
// 			{
// 				count++;
// 				if (elem == 'P')
// 				{
// 					game->player.y = y;
// 					game->player.x = x;
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (count);
// }

// int	check_elems(t_game *game)//errors 2
// {
// 	int	p;
// 	int	e;
// 	// int	x;
	
// 	p = count_elem(game, 'P');
// 	e = count_elem(game, 'E');
// 	game->nb_collect = count_elem(game, 'C');
// 	// x = count_elem(game, 'X');
// 	if (p != 1 || e != 1 || !game->nb_collect)//don't forget to add X is you do enemies
// 		return (false);//something fucked up
// 	return (true);//all is good!
// }

// // int	check_size(t_game *game)//erros 2
// // {
// // 	if ((game->height * TILESET) > 720 || (game->width * TILESET) > 1080)
// // 	//should I round down? 1000x700??
// // 		return (false);//too big
// // 	return (true);
// // }

// void	error_map_exit(t_game *game, char *message)//errors 2 (or maybe close?)
// {
// 	ft_printf("Error: %s\n", message);
// 	close_map(game);
// }

// int	in_tab(int tab[100][2], int y, int x)//parsing
// {
// 	int i;

// 	i = 0;
// 	while (i < 1000)
// 	{
// 		if (tab[i][0] == y && tab[i][1] == x)
// 			return (1);
// 		else if (tab[i][0] == 0 && tab[i][1] == 0)
// 		{
// 			tab[i][0] = y;
// 			tab[i][1] = x;
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void dfs(t_game *game, int tab[100][2], int y, int x)//parsing
// {
// 	if (game->map[y][x] == 'C')
// 		game->dfs_collect++;
// 	if (game->map[y][x] == 'E')
// 		game->dfs_exit++;
// 	if (game->map[y][x - 1] != '1' && !in_tab(tab, y, x - 1))//left __ && != 'X'??
// 	{
// 		dfs(game, tab, y, x - 1);
// 		// ft_printf("row %d col %d got left\n", y, x);
// 	}
// 	if (game->map[y - 1][x] != '1' && !in_tab(tab, y - 1, x))//up
// 	{
// 		dfs(game, tab, y - 1, x);
// 		// ft_printf("row %d col %d got up\n", y, x);
// 	}
// 	if (game->map[y][x + 1] != '1' && !in_tab(tab, y, x + 1))//right
// 	{
// 		dfs(game, tab, y, x + 1);
// 		// ft_printf("row %d col %d got right\n", y, x);
// 	}
// 	if (game->map[y + 1][x] != '1' && !in_tab(tab, y + 1, x))//down
// 	{
// 		dfs(game, tab, y + 1, x);
// 		// ft_printf("row %d col %d got down\n", y, x);
// 	}
// }
// int check_map(t_game *game)//parsing
// {
// 	int tab[1000][2] = {0};
// 	game->dfs_collect = 0;
// 	game->dfs_exit = 0;

// 	dfs(game, tab, game->player.y, game->player.x);
// 	if (game->dfs_exit == 1 && game->dfs_collect == game->nb_collect)
// 		return (true);
// 	return (false);
// }


// bool	valid_map(t_game *game)//errors 2
// {
// 	if (!check_rectangular(game))
// 		return (error_map_exit(game, "map is not rectangular"), false);
// 	if (!check_frame(game))
// 		return (error_map_exit(game, "missing walls!"), false);
// 	if (!check_chars(game))
// 		return (error_map_exit(game, "intruders, intrudeeers!!"), false);
// 	if (!check_elems(game))
// 		return (error_map_exit(game, "nah, brother, things are amiss"), false);
// 	// if (!check_size(game))
// 	// 	return (error_map_exit(game, "map might exceeds screen limits"), false);
// 	if (!check_map(game))
// 		return (error_map_exit(game, "pigeon can't go home"), false);
// 	return (true);//should not even return anything actually
// }
