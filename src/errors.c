/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:18 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 17:38:26 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ber(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (ft_strncmp(str + (len - 4), ".ber", 4))
		return (0);
	return (1);
}

int	errors(t_game *game, int argc, char **argv, char ***map)
{
	int		fd;

	if (argc != 2)
		exit (1);
	if (!ber(argv[1]))
		exit (4);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (2);
	*map = extract(fd);
	if (*map == NULL)
		exit (3);
	close(fd);
	if (!parsing(game, *map))
		exit (free_map(NULL, *map) + 4);
	if (!goodway(*map))
		exit (free_map(NULL, *map) + 5);
	return (0);
}
