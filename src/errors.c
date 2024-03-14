#include "../include/so_long.h"

static int	ber(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (ft_strncmp(str + (len - 4), ".ber", 4))
		return (0);
	return (1);
}

int	errors(int argc, char **argv, char ***map)
{
	int		fd;

	if (argc != 2)
		return (1);
	if (!ber(argv[1]))
		return (4);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (2);
	*map = extract(fd);
	if (*map == NULL)
		return (3);
	close(fd);
	if (!parsing(*map))
		return (free_map(NULL, *map) + 4);
	if (!goodway(*map))
		return (free_map(NULL, *map) + 5);
	return (0);
}
