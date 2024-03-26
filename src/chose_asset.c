/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:11 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 15:46:12 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	wall_1(t_game *game, int i, int j)
{
	if (j > 0 && game->map[i][j - 1] == '1')
		return (WD);
	if (i > 0 && game->map[i - 1][j] == '1')
		return (WD);
	if (j < game->width - 1 && game->map[i][j + 1] == '1')
		return (WD);
	if (i < game->height - 1 && game->map[i + 1][j] == '1')
		return (WPD);
	return (0);
}

static int	exep(t_game *game, int i, int j)
{
	if (game->map[i + 1][j - 1] == '1'
		&& game->map[i + 1][j + 1] != '1')
		return (WDCUL);
	if (game->map[i + 1][j - 1] != '1'
		&& game->map[i + 1][j + 1] == '1')
		return (WDCUR);
	if (game->map[i + 1][j - 1] == '1'
		&& game->map[i + 1][j + 1] == '1')
		return (WPU);
	if (game->map[i + 1][j - 1] != '1'
		&& game->map[i + 1][j + 1] != '1')
		return (WD);
	return (0);
}

int	wall_3(t_game *game, int i, int j)
{
	if (i > 0 && game->map[i - 1][j] != '1')
		return (WU);
	if (j > 0 && game->map[i][j - 1] != '1')
		return (WL);
	if (i < game->height - 1 && game->map[i + 1][j] != '1')
		return (exep(game, i, j));
	if (j < game->width - 1 && game->map[i][j + 1] != '1')
		return (WR);
	return (0);
}

int	wall_0(t_game *game, int i, int j)
{
	if (i > 0 && game->map[i - 1][j] == '1')
		return (W);
	return (WD);
}

int	wall_2(t_game *game, int i, int j)
{
	if (i > 0 && j > 0 && game->map[i - 1][j] == '1'
		&& game->map[i][j - 1] == '1')
		return (WD);
	if (j > 0 && i < game->height - 1 && game->map[i][j - 1] == '1'
		&& game->map[i + 1][j] == '1')
		return (WCUR);
	if (i > 0 && j < game->width - 1 && game->map[i - 1][j] == '1'
		&& game->map[i][j + 1] == '1')
		return (WD);
	if (i < game->height - 1 && j < game->width - 1 &&
		game->map[i + 1][j] == '1' && game->map[i][j + 1] == '1')
		return (WCUL);
	if (i > 0 && i < game->height - 1 && game->map[i - 1][j] == '1'
		&& game->map[i + 1][j] == '1')
		return (WD);
	if (j > 0 && j < game->width - 1 && game->map[i][j - 1] == '1'
		&& game->map[i][j + 1] == '1')
		return (WLR);
	return (0);
}
