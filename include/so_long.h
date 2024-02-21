#ifndef SO_LONG_H

# define SO_LONG_H

# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"

typedef struct s_items	t_items;

int		parsing(int fd);
int		free_error(char *str, char *tmp);

struct	s_items
{
	int	exit;
	int	player;
	int	collect;
};

#endif
