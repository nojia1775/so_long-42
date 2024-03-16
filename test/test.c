#include "../include/so_long.h"

typedef struct s_s	_s;

struct s_s
{
	void	*mlx;
	void	*win;
	void	*img;
	int	width;
	int	height;
};

int	main(void)
{
	_s	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 500, 500, "");
	if (!data.win)
		return (2);
	ft_printf("ok\n");
	data.img = mlx_xpm_file_to_image(data.mlx, "test.xpm", &data.width, &data.height);
	if (!data.img)
		return (3);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}