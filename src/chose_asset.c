#include "../include/so_long.h"

int	wall_1(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] == '1')
		return (14);
	if (game->map[i - 1][j] == '1')
		return (12);
	if (game->map[i][j + 1] == '1')
		return (13);
	if (game->map[i + 1][j] == '1')
		return (15);
	return (0);
}

int	wall_3(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] != '1')
		return (2);
	if (game->map[i][j - 1] != '1')
		return (5);
	if (game->map[i + 1][j] != '1')
		return (3);
	if (game->map[i][j + 1] != '1')
		return (4);
	return (0);
}

int	wall_0(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == '1')
		return (0);
	return (1);
}

int	wall_2(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == '1' && game->map[i][j - 1] == '1')
		return (7);
	if (game->map[i][j - 1] == '1' && game->map[i + 1][j] == '1')
		return (9);
	if (game->map[i - 1][j] == '1' && game->map[i][j + 1] == '1')
		return (6);
	if (game->map[i + 1][j] == '1' && game->map[i][j + 1] == '1')
		return (8);
	if (game->map[i - 1][j] == '1' && game->map[i + 1][j] == '1')
		return (11);
	if (game->map[i][j - 1] == '1' && game->map[i][j + 1] == '1')
		return (10);
	return (0);
}
