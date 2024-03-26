/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:46:24 by nadjemia          #+#    #+#             */
/*   Updated: 2024/03/26 15:46:25 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**wall_files(void)
{
	char	**files;

	files = (char **)malloc(sizeof(char *) * 12);
	if (!files)
		return (NULL);
	files[0] = "textures/wall/wall.xpm";
	files[1] = "textures/wall/wall_cul.xpm";
	files[2] = "textures/wall/wall_cur.xpm";
	files[3] = "textures/wall/wall_d_cul.xpm";
	files[4] = "textures/wall/wall_d_cur.xpm";
	files[5] = "textures/wall/wall_down.xpm";
	files[6] = "textures/wall/wall_left.xpm";
	files[7] = "textures/wall/wall_right.xpm";
	files[8] = "textures/wall/wall_up.xpm";
	files[9] = "textures/wall/wall_lr.xpm";
	files[10] = "textures/wall/wall_point_u.xpm";
	files[11] = "textures/wall/wall_point_d.xpm";
	return (files);
}
