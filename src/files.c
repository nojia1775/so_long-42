#include "../include/so_long.h"

char	**wall_files(void)
{
	char	**files;

	files = (char **)malloc(sizeof(char *) * 16);
	if (!files)
		return (NULL);
	files[0] = "textures/wall/wall.xpm";
	files[1] = "textures/wall/wall_down.xpm";
	files[2] = "textures/wall/wall_up.xpm";
	files[3] = "textures/wall/wall_down.xpm";
	files[4] = "textures/wall/wall_right.xpm";
	files[5] = "textures/wall/wall_left.xpm";
	files[6] = "textures/wall/wall_down.xpm";
	files[7] = "textures/wall/wall_down.xpm";
	files[8] = "textures/wall/wall_cul.xpm";
	files[9] = "textures/wall/wall_cur.xpm";
	files[10] = "textures/wall/wall_lr.xpm";
	files[11] = "textures/wall/wall_ud.xpm";
	files[12] = "textures/wall/wall_down.xpm";
	files[13] = "textures/wall/wall_down.xpm";
	files[14] = "textures/wall/wall_down.xpm";
	files[15] = "textures/wall/wall_point_u.xpm";
	return (files);
}

// char	**wall_files(void)
// {
// 	char	**files;

// 	files = (char **)malloc(sizeof(char *) * 16);
// 	if (!files)
// 		return (NULL);
// 	files[0] = "textures/wall/wall.xpm";
// 	files[1] = "textures/wall/wall_solo.xpm";
// 	files[2] = "textures/wall/wall_up.xpm";
// 	files[3] = "textures/wall/wall_down.xpm";
// 	files[4] = "textures/wall/wall_right.xpm";
// 	files[5] = "textures/wall/wall_left.xpm";
// 	files[6] = "textures/wall/wall_cdl.xpm";
// 	files[7] = "textures/wall/wall_cdr.xpm";
// 	files[8] = "textures/wall/wall_cul.xpm";
// 	files[9] = "textures/wall/wall_cur.xpm";
// 	files[10] = "textures/wall/wall_lr.xpm";
// 	files[11] = "textures/wall/wall_ud.xpm";
// 	files[12] = "textures/wall/wall_point_d.xpm";
// 	files[13] = "textures/wall/wall_point_l.xpm";
// 	files[14] = "textures/wall/wall_point_r.xpm";
// 	files[15] = "textures/wall/wall_point_u.xpm";
// 	return (files);
// }
