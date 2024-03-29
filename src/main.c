/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:12 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 19:16:58 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_mov(t_game *game)
{
	char	*mov;

	mov = ft_itoa(game->mov);
	my_mlx_xpm_file_to_image(game, "textures/wall/wall.xpm");
	my_mlx_put_image_to_window(game, 0, 0);
	mlx_destroy_image(game->data->mlx, game->data->img);
	mlx_string_put(game->data->mlx, game->data->win, 14, 20,
		0xFFFFFF, mov);
	ft_printf("%s\n", mov);
	free(mov);
}

static int	close_win(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	mlx_destroy_window(game->data->mlx, game->data->win);
	mlx_destroy_display(game->data->mlx);
	free_all(game, 0);
	exit(0);
	return (1);
}

static int	escp_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_win(game);
	else if (keycode == 65363 || keycode == 100)
		return (go_right(game) || close_win(game));
	else if (keycode == 65361 || keycode == 97)
		return (go_left(game) || close_win(game));
	else if (keycode == 65362 || keycode == 119)
		return (go_up(game) || close_win(game));
	else if (keycode == 65364 || keycode == 115)
		return (go_down(game) || close_win(game));
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	errors(&game, argc, argv, &map);
	init_game(&game, map);
	my_mlx_init(&game);
	verif_text(&game);
	my_mlx_new_window(&game, game.width * 32, game.height * 32, "SO_LONG");
	display_map(&game);
	print_mov(&game);
	mlx_key_hook(game.data->win, escp_keypress, &game);
	mlx_hook(game.data->win, 17, 0, close_win, &game);
	mlx_loop(game.data->mlx);
	free_all(&game, 1);
	return (0);
}
