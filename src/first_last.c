/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:27 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	first_line(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == '1')
		return (W);
	else if (game->map[i + 1][j] != '1' 
		&& game->map[i + 1][j - 1] == '1'
		&& game->map[i + 1][j + 1] != '1')
		return (WDCUL);
	else if (game->map[i + 1][j] != '1' 
		&& game->map[i + 1][j - 1] != '1'
		&& game->map[i + 1][j + 1] == '1')
		return (WDCUR);
	else if (game->map[i + 1][j] != '1' 
		&& game->map[i + 1][j - 1] != '1'
		&& game->map[i + 1][j + 1] != '1')
		return (WD);
	else if (game->map[i + 1][j] != '1' 
		&& game->map[i + 1][j - 1] == '1'
		&& game->map[i + 1][j + 1] == '1')
		return (WPU);
	else if (game->map[i + 1][j] == '1')
		return (WD);
	return (WD);
}

int	firsto_cl(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] == '1')
		return (W);
	else
		return (WR);
}

int	last_line(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == '1')
		return (W);
	else
		return (WU);
}

int	lasto_cl(t_game *game, int i, int j)
{
	if (game->map[i][j - 1] == '1')
		return (W);
	else
		return (WL);
}