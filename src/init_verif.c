/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:05 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 17:59:18 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_init(t_game *game)
{
	game->data->mlx = mlx_init();
	if (!game->data->mlx)
	{
		free_map(NULL, game->map);
		free(game->data);
		exit(6);
	}
}

void	my_mlx_new_window(t_game *game, int width, int height, char *tle)
{
	game->data->win = mlx_new_window(game->data->mlx, width, height, tle);
	if (!game->data->win)
	{
		free_map(NULL, game->map);
		mlx_destroy_display(game->data->mlx);
		exit(5);
	}
}

void	init_game(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->data = (t_data *)malloc(sizeof(t_data));
	if (!game->data)
	{
		free_map(NULL, map);
		exit(6);
	}
	while (map[i])
		i++;
	game->map = map;
	game->width = ft_strlen(map[0]) - 1;
	game->height = i;
	game->collected = 0;
}

void	my_mlx_xpm_file_to_image(t_game *game, char *file)
{
	game->data->img = mlx_xpm_file_to_image(game->data->mlx, file,
		&game->data->width, &game->data->height);
	if (!game->data->img)
	{
		mlx_destroy_window(game->data->mlx, game->data->win);
		mlx_destroy_display(game->data->mlx);
		free_all(game, 0);
		exit(7);
	}
}

void	my_mlx_put_image_to_window(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->img, x, y);
}