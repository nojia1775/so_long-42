#ifndef SO_LONG_H

# define SO_LONG_H

# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"

typedef struct s_items	t_items;
typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_good	t_good;

int		parsing(char **map);
int		free_error(char *str, char *tmp);
char	**extract(int fd);
int	free_map(t_map **map, char **mapping);
size_t	modif_strlen(const char *str);
int		goodway(char **map);
int		line(char **str, int i, int j);
int		row(char **str, int i, int j);
void	isitem(char *c);
int		canreachitems(char **map);
int		errors(int argc, char **argv, char ***map);

struct	s_good
{
	int	exit;
	int	collect;
};

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
