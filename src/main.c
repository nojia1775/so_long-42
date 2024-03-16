/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:12 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/27 11:16:19 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_win(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	mlx_destroy_window(game->data->mlx, game->data->win);
	mlx_destroy_display(game->data->mlx);
	free_map(NULL, game->map);
	exit(6);
}

static int	escp_keypress(int keycode, t_data *game)
{
	if (keycode == 65307)
		close_win(game);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	errors(argc, argv, &map);
	init_game(&game, map);
	my_mlx_init(&game);
	game.data->win = my_mlx_new_window(&game, 1920, 1080, "SO_LONG");
	mlx_key_hook(data.win, escp_keypress, &game);
	mlx_hook(game.data->win, 17, 0, close_win, &game);
	mlx_loop(game.data->mlx);
	mlx_destroy_window(game.data->mlx, game.data->win);
	mlx_destroy_display(game.data->mlx);
	free_map(NULL, game.map);
	return (0);
}
