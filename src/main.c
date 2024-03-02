/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:12 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/27 11:16:19 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (errors(argc, argv, &map))
		return (errors(argc, argv, &map));
	int i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	free_map(NULL, map);
	return (0);
}
