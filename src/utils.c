/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:39:12 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/27 15:39:13 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	modif_strlen(const char *str)
{
	size_t	n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			n++;
		i++;
	}
	return (n);
}

void	isitem(char *c)
{
	if (*c == 'C')
		*c = 'c';
	else if (*c == 'E')
		*c = 'e';
}

int	row(char **str, int i, int j)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = i;
	while (str[++i][j] != '1')
	{
		isitem(&str[i][j]);
		if (str[i][j] == '0')
		{
			count++;
			str[i][j] = '.';
		}
	}
	i = tmp;
	while (str[--i][j] != '1')
	{
		isitem(&str[i][j]);
		if (str[i][j] == '0')
		{
			count++;
			str[i][j] = '.';
		}
	}
	return (count);
}

int	canreachitems(char **map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			else if (map[i][j] == '.')
				map[i][j] = '0';
			else if (map[i][j] == 'c')
				map[i][j] = 'C';
			else if (map[i][j] == 'e')
				map[i][j] = 'E';
			j++;
		}
		i++;
	}
	return (1);
}
