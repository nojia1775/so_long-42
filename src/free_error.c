/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:02 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/29 19:01:11 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_error(char *str, char *tmp)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (0);
}

void	free_all(t_game *game, int destroy)
{
	if (destroy)
	{
		mlx_destroy_window(game->data->mlx, game->data->win);
		mlx_destroy_image(game->data->mlx, game->data->img);
		mlx_destroy_display(game->data->mlx);
	}
	free_map(NULL, game->map);
	free(game->data->mlx);
	free(game->data);
} 
