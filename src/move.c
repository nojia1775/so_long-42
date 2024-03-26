/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:42 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	go_right(t_game *game)
{
	int	i;
	int	j;

	findplayer(game->map, &i, &j);
	if (game->map[i][j + 1] != '1')
	{
		if (game->map[i][j + 1] == 'C')
			game->collected++;
		if (game->map[i][j + 1] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i][j + 1] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		game->map[i][j] = '0';
		my_mlx_xpm_file_to_image(game,
			"textures/floor/floor.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
		game->map[i][j + 1] = 'P';
		my_mlx_xpm_file_to_image(game,
			"textures/character/stand/right.xpm");
		my_mlx_put_image_to_window(game, (j + 1) * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
	}
	return (1);
}

int	go_left(t_game *game)
{
	int	i;
	int	j;

	findplayer(game->map, &i, &j);
	if (game->map[i][j - 1] != '1')
	{
		if (game->map[i][j - 1] == 'C')
			game->collected++;
		if (game->map[i][j - 1] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i][j - 1] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		game->map[i][j] = '0';
		my_mlx_xpm_file_to_image(game,
			"textures/floor/floor.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
		game->map[i][j - 1] = 'P';
		my_mlx_xpm_file_to_image(game,
			"textures/character/stand/left.xpm");
		my_mlx_put_image_to_window(game, (j - 1) * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
	}
	return (1);
}

int	go_up(t_game *game)
{
	int	i;
	int	j;

	findplayer(game->map, &i, &j);
	if (game->map[i - 1][j] != '1')
	{
		if (game->map[i - 1][j] == 'C')
			game->collected++;
		if (game->map[i - 1][j] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i - 1][j] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		game->map[i][j] = '0';
		my_mlx_xpm_file_to_image(game,
			"textures/floor/floor.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
		game->map[i - 1][j] = 'P';
		my_mlx_xpm_file_to_image(game,
			"textures/character/stand/up.xpm");
		my_mlx_put_image_to_window(game, j * 32, (i - 1) * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
	}
	return (1);
}

int	go_down(t_game *game)
{
	int	i;
	int	j;

	findplayer(game->map, &i, &j);if (game->map[i][j + 1] == 'E' && game->to_c != game->collected)
			return (1);
	if (game->map[i + 1][j] != '1')
	{
		if (game->map[i + 1][j] == 'C')
			game->collected++;
		if (game->map[i + 1][j] == 'E' && game->to_c != game->collected)
			return (1);
		if (game->map[i + 1][j] == 'E'
			&& game->collected == game->to_c)
			return (ft_printf("You won!\n"), 0);
		game->map[i][j] = '0';
		my_mlx_xpm_file_to_image(game,
			"textures/floor/floor.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
		game->map[i + 1][j] = 'P';
		my_mlx_xpm_file_to_image(game,
			"textures/character/stand/down.xpm");
		my_mlx_put_image_to_window(game, j * 32, (i + 1) * 32);
		mlx_destroy_image(game->data->mlx, game->data->img);
	}
	return (1);
}