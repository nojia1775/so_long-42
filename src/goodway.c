#include "../include/so_long.h"

static void	findplayer(char **map, int *i, int *j)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				*i = x;
				*j = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	turn2(char **map, int *x, int *y, int op)
{
	int	tmp;

	tmp = *x;
	while (map[*x][*y] != '1')
	{
		if (map[*x][*y] != 'C' && map[*x][*y] != 'P')
			map[*x][*y] = '2';
		while (map[*x][*y] != '1')
		{
			if (map[*x][*y] != 'C' && map[*x][*y] != 'P')
				map[*x][*y] = '2';
			if (map[*x + 1][*y] != '2' && map[*x + 1][*y] != '1')
				(*x)++;
			else if (map[*x - 1][*y] != '2'
				&& map[*x - 1][*y] != '1')
				(*x)--;
			else
				break ;
		}
		*x = tmp;
		if (op % 2 == 0)
			(*y)++;
		else
			(*y)--;
	}
}

static int	findway(char **map, int *i, int *j)
{
	int	x;
	int	y;

	x = *i;
	y = *j;
	
	turn2(map, &x, &y, 2);
	x = *i;
	y = *j;
	turn2(map, &x, &y, 1);
	return (0);
}

int	goodway(char **map)
{
	int		i;
	int		j;

	findplayer(map, &i, &j);
	findway(map, &i, &j);
	return (0);
}
