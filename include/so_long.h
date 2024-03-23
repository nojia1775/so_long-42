#ifndef SO_LONG_H

# define SO_LONG_H

# define W 0 
# define WCUL 1
# define WCUR 2
# define WDCUL 3
# define WDCUR 4
# define WD 5
# define WL 6
# define WR 7
# define WU 8
# define WLR 9
# define WPU 10
# define WPD 11

# include "../FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_items	t_items;
typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_good	t_good;
typedef struct s_game	t_game;

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
void	my_mlx_new_window(t_game *game, int width, int height, char *tle);
void	my_mlx_init(t_game *game);
void	init_game(t_game *game, char **map);
void	free_all(t_game *game, int destroy);
void	my_mlx_xpm_file_to_image(t_game *game, char *file);
void	display_map(t_game *game);
void	my_mlx_put_image_to_window(t_game *game, int x, int y);
char	**wall_files(void);
int	wall_1(t_game *game, int i, int j);
int	wall_3(t_game *game, int i, int j);
int	wall_0(t_game *game, int i, int j);
int	wall_2(t_game *game, int i, int j);
int		first_line(t_game *game, int i, int j);
int		first_col(t_game *game, int i, int j);
int		last_line(t_game *game, int i, int j);
int		last_col(t_game *game, int i, int j);

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
	void	*img;
	int		width;
	int		height;
};

struct	s_items
{
	int	exit;
	int	player;
	int	collect;
};

struct	s_game
{
	t_data	*data;
	char	**map;
	int	width;
	int	height;
};

#endif
