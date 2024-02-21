#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (2);
	if (!parsing(fd))
		return (ft_printf("Error\n") - 3);
	close(fd);
	return (0);
}
