/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:14 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 20:23:56 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	nbr_void(t_game *game, int i, int j)
{
	int	nbr;

	nbr = 0;
	if (i > 0 && game->map[i - 1][j] != '1')
		nbr++;
	if (j > 0 && game->map[i][j - 1] != '1')
		nbr++;
	if (i < game->height - 1 && game->map[i + 1][j] != '1')
		nbr++;
	if (j < game->width - 1 && game->map[i][j + 1] != '1')
		nbr++;
	return (nbr);
}

static int	which_wall(t_game *game, int i, int j)
{
	if (i == 0)
		return (first_line(game, i, j));
	if (j == 0)
		return (firsto_cl(game, i, j));
	if (i == game->height - 1)
		return (last_line(game, i, j));
	if (j == game->width - 1)
		return (lasto_cl(game, i, j));
	if (nbr_void(game, i, j) == 1)
		return (wall_3(game, i, j));
	if (nbr_void(game, i, j) == 3)
		return (wall_1(game, i, j));
	if (nbr_void(game, i, j) == 4 || nbr_void(game, i, j) == 0)
		return (wall_0(game, i, j));
	if (nbr_void(game, i, j) == 2)
		return (wall_2(game, i, j));
	return (W);
}

static void	display(t_game *game, char *file, int i, int j)
{
	my_mlx_xpm_file_to_image(game, file);
	my_mlx_put_image_to_window(game, j * 32, i * 32);
	mlx_destroy_image(game->data->mlx, game->data->img);
}

void	display_map(t_game *game)
{
	char	**files;
	int		i;
	int		j;

	files = wall_files();
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				display(game, files[which_wall(game, i, j)], i, j);
			else if (game->map[i][j] == '0')
				display(game, "textures/floor/floor.xpm", i, j);
			else if (game->map[i][j] == 'P')
				display(game, "textures/character/down.xpm", i, j);
			else if (game->map[i][j] == 'E')
				display(game, "textures/door/door.xpm", i, j);
			else if (game->map[i][j] == 'C')
				display(game, "textures/collect/collect.xpm", i, j);
		}
	}
	free(files);
}
