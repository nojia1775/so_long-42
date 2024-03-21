/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:05:02 by nadjemia          #+#    #+#             */
/*   Updated: 2024/02/27 11:05:04 by nadjemia         ###   ########.fr       */
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

void	free_all(t_game *game)
{
	free_map(NULL, game->map);
	free(game->data->mlx);
	free(game->data);
}
