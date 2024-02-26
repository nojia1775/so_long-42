#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		i;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (2);
	map = extract(fd);
	close(fd);
	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	return (0);
}
