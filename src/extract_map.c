#include "../include/so_long.h"

static void	free_map(t_map **map, char **mapping)
{
	t_map	*cur;
	t_map	*rm;
	int	i;

	i = 0;
	cur = *map;
	while (cur)
	{
		rm = cur;
		cur = cur->next;
		free(rm->line);
		free(rm);
	}
	while (mapping[i])
		free(mapping[i++]);
	free(mapping);
}

static void	new_line(t_map **map, char *str)
{
	t_map	*cur;

	if (!(*map))
	{
		*map = (t_map *)malloc(sizeof(**map));
		if (!(*map))
			return ;
		(*map)->line = ft_strdup(str);
		if (!(*map))
			return (free(*map));
		(*map)->next = NULL;
	}
	else
	{
		cur = *map;
		while (cur->next)
			cur = cur->next;
		cur->next = (t_map *)malloc(sizeof(*(cur->next)));
		if (!(cur->next))
			return ;
		cur->next->line = ft_strdup(str);
		if (!cur->next->line)
			return (free_map(map, NULL));
		cur->next->next = NULL;
	}
}

static int	lstsize(t_map *map)
{
	t_map	*cur;
	int	size;

	size = 0;
	cur = map;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return (size);
}

static char	**lsttoarr(t_map *map, int size)
{
	int	i;
	t_map	*cur;
	char	**mapping;

	i = 0;
	mapping = (char **)malloc(sizeof(char *) * (size + 1));
	if (!mapping)
		return (NULL);
	mapping[size] = NULL;
	cur = map;
	while (i < size)
	{
		mapping[i] = ft_strdup(cur->line);
		if (!mapping[i])
		{
			free_map(&map, mapping);
			return (NULL);
		}
		cur = cur->next;
		i++;
	}
	return (mapping);
}

char	**extract(int fd)
{
	char	*str;
	t_map	*map;
	char	**mapping;

	str = get_next_line(fd);
	map = NULL;
	while (str)
	{
		new_line(&map, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	mapping = lsttoarr(map, lstsize(map));
	if (!mapping)
		return (NULL);
	free_map(&map, NULL);
	return (mapping);
}
