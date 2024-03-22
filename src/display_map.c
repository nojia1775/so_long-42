#include "../include/so_long.h"

static int	nbr_void(t_game *game, int i, int j)
{
	int	nbr;

	nbr = 0;
	if (game->map[i - 1][j] != '1')
		nbr++;
	if (game->map[i][j - 1] != '1')
		nbr++;
	if (game->map[i + 1][j] != '1')
		nbr++;
	if (game->map[i][j + 1] != '1')
		nbr++;
	return (nbr);
}

static int	which_wall(t_game *game, int i, int j)
{
	if (i > 0 && i < game->height - 2 && j > 0 && j < game->width - 2)
	{
		if (nbr_void(game, i, j) == 1)
			return (wall_3(game, i, j));
		if (nbr_void(game, i, j) == 3)
			return (wall_1(game, i, j));
		if (nbr_void(game, i, j) == 4 || nbr_void(game, i, j) == 0)
			return (wall_0(game, i, j));
		if (nbr_void(game, i, j) == 2)
			return (wall_2(game, i, j));
	}
	if (i == 0 && game->map[i + 1][j] != '1')
	{
		my_mlx_xpm_file_to_image(game, "textures/wall/wall_down.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
	}
	else if (i == 0 && game->map[i + 1][j] == '1')
	{
		my_mlx_xpm_file_to_image(game, "textures/wall/wall.xpm");
		my_mlx_put_image_to_window(game, j * 32, i * 32);
	}
	return (0);
}

static void	display(t_game *game, char *file, int i, int j)
{
	ft_printf("%s\n", file);
	my_mlx_xpm_file_to_image(game, file);
	my_mlx_put_image_to_window(game, j * 32, i * 32);
}

void	display_map(t_game *game)
{
	char	**files;
	int		i;
	int		j;

	files = wall_files();
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_printf("x = %d y = %d %c\n", j, i, game->map[i][j]);
			if (game->map[i][j] == '1')
				display(game, files[which_wall(game, i, j)], i, j);
			else if (game->map[i][j] == '0')
				display(game, "textures/floor/floor.xpm", i, j);
			else if (game->map[i][j] == 'P')
				display(game, "textures/character/stand/down.xpm", i, j);
			else if (game->map[i][j] == 'E')
				display(game, "textures/character/stand/up.xpm", i, j);
			else if (game->map[i][j] == 'C')
				display(game, "textures/character/stand/left.xpm", i, j);
			j++;
		}
		i++;
	}
	free(files);
}















// void	display_map(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			ft_printf("%d %d\n", j, i);
// 			if (game->map[i][j] == '0')
// 			{
// 				my_mlx_xpm_file_to_image(game, "textures/floor/floor.xpm");
// 				my_mlx_put_image_to_window(game, j * 32, i * 32);
// 			}
// 			else if (game->map[i][j] == 'P')
// 			{
// 				my_mlx_xpm_file_to_image(game, "textures/character/stand/down.xpm");
// 				my_mlx_put_image_to_window(game, j * 32, i * 32);
// 			}
// 			else if (game->map[i][j] == '1' && i < game->height - 1 && j < game->width - 1 && i > 1 && j > 1)
// 			{
// 				if (game->map[i + 1][j] != '1' && game->map[i][j - 1] != '1' && game->map[i - 1][j] != '1' && game->map[i][j + 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_solo.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i - 1][j] != '1' && game->map[i][j - 1] != '1' && game->map[i][j + 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_point_l.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i - 1][j] != '1' && game->map[i + 1][j] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_ud.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i + 1][j] != '1' && game->map[i][j - 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_cdl.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i + 1][j] != '1' && game->map[i][j + 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_cdr.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i - 1][j] != '1' && game->map[i][j - 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_cul.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i + 1][j] != '1' && game->map[i][j + 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_cur.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i + 1][j] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_down.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i - 1][j] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_up.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i][j - 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_left.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else if (game->map[i][j + 1] != '1')
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall_right.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 				else
// 				{
// 					my_mlx_xpm_file_to_image(game, "textures/wall/wall.xpm");
// 					my_mlx_put_image_to_window(game, j * 32, i * 32);
// 				}
// 			}
// 			else if (game->map[i][j] == '1')
// 			{
// 				my_mlx_xpm_file_to_image(game, "textures/wall/wall.xpm");
// 				my_mlx_put_image_to_window(game, j * 32, i * 32);
// 			}
// 			else if (game->map[i][j] == 'E')
// 			{
// 				my_mlx_xpm_file_to_image(game, "textures/character/stand/up.xpm");
// 				my_mlx_put_image_to_window(game, j * 32, i * 32);
// 			}
// 			else if (game->map[i][j] == 'C')
// 			{
// 				my_mlx_xpm_file_to_image(game, "textures/character/stand/left.xpm");
// 				my_mlx_put_image_to_window(game, j * 32, i * 32);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
