/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:42:16 by noah              #+#    #+#             */
/*   Updated: 2024/03/29 20:26:05 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**textures(void)
{
	char	**text;

	text = (char **)malloc(sizeof(char *) * 20);
	if (!text)
		return (NULL);
	text[0] = "textures/character/down.xpm";
	text[1] = "textures/character/right.xpm";
	text[2] = "textures/character/left.xpm";
	text[3] = "textures/character/up.xpm";
	text[4] = "textures/door/door.xpm";
	text[5] = "textures/collect/collect.xpm";
	text[6] = "textures/floor/floor.xpm";
	text[7] = "textures/wall/wall_cul.xpm";
	text[8] = "textures/wall/wall_cur.xpm";
	text[9] = "textures/wall/wall_d_cul.xpm";
	text[10] = "textures/wall/wall_d_cur.xpm";
	text[11] = "textures/wall/wall_down.xpm";
	text[12] = "textures/wall/wall_left.xpm";
	text[13] = "textures/wall/wall_lr.xpm";
	text[14] = "textures/wall/wall_point_d.xpm";
	text[15] = "textures/wall/wall_point_u.xpm";
	text[16] = "textures/wall/wall_right.xpm";
	text[17] = "textures/wall/wall_up.xpm";
	text[18] = "textures/wall/wall.xpm";
	return (text);
}

static void	free_text(t_game *game, char **text)
{
	free(text);
	mlx_destroy_display(game->data->mlx);
	free_map(NULL, game->map);
	free(game->data->mlx);
	free(game->data);
	exit(ft_printf("Error : textures\n") - 7);
}

void	verif_text(t_game *game)
{
	char	**text;
	int		i;

	text = textures();
	if (!text)
		free_text(game, text);
	text[19] = NULL;
	i = 0;
	while (text[i])
	{
		game->data->img = mlx_xpm_file_to_image(game->data->mlx,
				text[i], &game->data->width,
				&game->data->height);
		if (!game->data->img)
			free_text(game, text);
		mlx_destroy_image(game->data->mlx, game->data->img);
		i++;
	}
	free(text);
}
