#include "../include/so_long.h"

static int	isone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	wrongchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && (i == 0 || str[i + 1] == '\n'))
			return (ft_printf("map pas fermee cote\n") - 19);
		if (str[i] != '0' && str[i] != '1' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != 'C'
			&& str[i] != '\n')
			return (ft_printf("erreur char\n") - 11);
		i++;
	}
	return (0);
}

int	check_items(char *str, t_items *items)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P' && items->player > 0)
			return (0);
		else if (str[i] == 'P' && items->player == 0)
			items->player++;
		if (str[i] == 'C')
			items->collect++;
		if (str[i] == 'E' && items->exit > 0)
			return (0);
		else if (str[i] == 'E' && items->exit == 0)
			items->exit++;
		i++;
	}
	return (1);
}

static int	verif(int fd, char **tmp, t_items *items)
{
	char	*str;
	int		count;
	int		len;
	int		model;

	count = 0;
	str = get_next_line(fd);
	model = ft_strlen(str);
	while (str)
	{
		len = ft_strlen(str);
		if (count == 0 && !isone(str))
			return (free_error(str, *tmp));
		if (wrongchar(str) || len != model || !check_items(str, items))
			return (free_error(str, *tmp));
		if (*tmp)
			free(*tmp);
		*tmp = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		count++;
	}
	return (1);
}

int	parsing(int fd)
{
	char	*tmp;
	t_items	items;

	items.player = 0;
	items.exit = 0;
	items.collect = 0;
	tmp = NULL;
	if (!verif(fd, &tmp, &items))
		return (0);
	if (items.collect == 0 || items.player == 0 || items.exit == 0)
		return (0);
	if (!isone(tmp))
		return (ft_printf("map pas fermee bas\n") - 19);
	free(tmp);
	return (1);
}
