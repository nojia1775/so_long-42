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
	game.data = (t_data *)malloc(sizeof(t_data));
	if (!game.data)
	{
		free_map(NULL, map);
		exit(6);
	}
	game.map = map;
}