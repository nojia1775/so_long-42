/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:18 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 18:41:50 by noah             ###   ########.fr       */
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
		exit (ft_printf("Error : invalid argument(s)\n") - 27);
	if (!ber(argv[1]))
		exit (ft_printf("Error : map's format invalid\n") - 25);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (ft_printf("Error : can't open map\n") - 21);
	*map = extract(fd);
	if (*map == NULL)
		exit (ft_printf("Error : can't extract map\n") - 23);
	close(fd);
	if (!parsing(game, *map))
		exit (ft_printf("Error : invalid map\n") + free_map(NULL, *map) - 16);
	if (!goodway(*map))
		exit (ft_printf("Error : invalid path\n") + free_map(NULL, *map) - 16);
	return (0);
}
