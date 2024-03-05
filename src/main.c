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
	t_data	data;

	if (errors(argc, argv, &map))
		return (errors(argc, argv, &map));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "SO_LONG");
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free_map(NULL, map);
	return (0);
}
