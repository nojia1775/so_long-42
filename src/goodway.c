/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:32 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 20:20:21 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	findplayer(char **map, int *i, int *j)
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
				if (map[x + 1][y] == '0')
					map[x + 1][y] = '.';
				if (map[x - 1][y] == '0')
					map[x - 1][y] = '.';
				*i = x;
				*j = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static int	setmap(char **str, int (*f)(char **, int, int))
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '.' || str[i][j] == 'P'
				|| str[i][j] == 'c')
				count += f(str, i, j);
			j++;
		}
		i++;
	}
	return (count);
}

static int	findway(char **map, int x, int y)
{
	int	count;

	count = 1;
	line(map, x, y);
	while (count)
	{
		count = setmap(map, row);
		count += setmap(map, line);
	}
	return (0);
}

int	goodway(char **map)
{
	int		i;
	int		j;

	findplayer(map, &i, &j);
	findway(map, i, j);
	if (!canreachitems(map))
		return (0);
	return (1);
}
