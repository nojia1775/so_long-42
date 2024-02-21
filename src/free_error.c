#include "../include/so_long.h"

int	free_error(char *str, char *tmp)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (0);
}
