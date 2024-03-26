/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:19 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	isgood(char *line, t_items *items)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != 'C' && line[i] != '\n')
			return (0);
		if (line[i] == 'E' && items->exit > 0)
			return (0);
		else if (line[i] == 'E' && items->exit == 0)
			items->exit = 1;
		if (line[i] == 'P' && items->player > 0)
			return (0);
		if (line[i] == 'P')
			items->player = 1;
		if (line[i] == 'C')
			items->collect++;
		i++;
	}
	return (1);
}

static int	closed(char *line, size_t len)
{
	if (line[0] != '1')
		return (0);
	if (line[len - 1] == '\n')
	{
		if (line[len - 2] != '1')
			return (0);
	}
	else if (line[len - 1] != '1')
		return (0);
	return (1);
	
}

static int	isone(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	parsing(t_game *game, char **map)
{
	int		i;
	t_items	items;
	size_t	model;
	size_t	len;

	ft_bzero(&items, sizeof(items));
	model = modif_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		len = modif_strlen(map[i]);
		if (len != model)
			return (0);
		if (!isgood(map[i], &items))
			return (0);
		if (i == 0 && !isone(map[i]))
			return (0);
		if (!closed(map[i], len))
			return (0);
	}
	if (!isone(map[i - 1]) || items.collect == 0 || items.exit == 0
		|| items.player == 0)
		return (0);
	game->to_c = items.collect;
	return (1);
}
