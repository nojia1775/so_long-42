/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:42 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 20:00:42 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	swap_text(t_game *game, t_coor coor, char *file)
{
	game->map[coor.i][coor.j] = '0';
	my_mlx_xpm_file_to_image(game, "textures/floor/floor.xpm");
	my_mlx_put_image_to_window(game, coor.j * 32, coor.i * 32);
	mlx_destroy_image(game->data->mlx, game->data->img);
	game->map[coor.new_i][coor.new_j] = 'P';
	my_mlx_xpm_file_to_image(game, file);
	my_mlx_put_image_to_window(game, coor.new_j * 32, coor.new_i * 32);
	mlx_destroy_image(game->data->mlx, game->data->img);
}

int	go_right(t_game *game)
{
	int		i;
	int		j;
	t_coor	coor;

	findplayer(game->map, &i, &j);
	if (game->map[i][j + 1] != '1')
	{
		coor.i = i;
		coor.j = j;
		coor.new_i = i;
		coor.new_j = j + 1;
		if (game->map[i][j + 1] == 'C')
			game->collected++;
		if (game->map[i][j + 1] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i][j + 1] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		swap_text(game, coor, "textures/character/right.xpm");
		game->mov++;
		print_mov(game);
	}
	return (1);
}

int	go_left(t_game *game)
{
	int		i;
	int		j;
	t_coor	coor;

	findplayer(game->map, &i, &j);
	coor.i = i;
	coor.j = j;
	coor.new_i = i;
	coor.new_j = j - 1;
	if (game->map[i][j - 1] != '1')
	{
		if (game->map[i][j - 1] == 'C')
			game->collected++;
		if (game->map[i][j - 1] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i][j - 1] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		swap_text(game, coor, "textures/character/left.xpm");
		game->mov++;
		print_mov(game);
	}
	return (1);
}

int	go_up(t_game *game)
{
	int		i;
	int		j;
	t_coor	coor;

	findplayer(game->map, &i, &j);
	coor.i = i;
	coor.j = j;
	coor.new_i = i - 1;
	coor.new_j = j;
	if (game->map[i - 1][j] != '1')
	{
		if (game->map[i - 1][j] == 'C')
			game->collected++;
		if (game->map[i - 1][j] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i - 1][j] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		swap_text(game, coor, "textures/character/up.xpm");
		game->mov++;
		print_mov(game);
	}
	return (1);
}

int	go_down(t_game *game)
{
	int		i;
	int		j;
	t_coor	coor;

	findplayer(game->map, &i, &j);
	coor.i = i;
	coor.j = j;
	coor.new_i = i + 1;
	coor.new_j = j;
	if (game->map[i + 1][j] != '1')
	{
		if (game->map[i + 1][j] == 'C')
			game->collected++;
		if (game->map[i + 1][j] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i + 1][j] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		swap_text(game, coor, "textures/character/down.xpm");
		game->mov++;
		print_mov(game);
	}
	return (1);
}
