#ifndef SO_LONG_H

# define SO_LONG_H

# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"

typedef struct s_items	t_items;
typedef struct s_data	t_data;
typedef struct s_map	t_map;

int		parsing(int fd);
int		free_error(char *str, char *tmp);
char	**extract(int fd);

struct	s_map
{
	char	*line;
	t_map	*next;
};

struct	s_data
{
	void	*mlx;
	void	*win;
};

struct	s_items
{
	int	exit;
	int	player;
	int	collect;
};

#endif
