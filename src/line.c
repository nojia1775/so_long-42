/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 20:04:13 by noah              #+#    #+#             */
/*   Updated: 2024/03/29 20:19:53 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	line2(char **str, int i, int j, int *count)
{
	while (str[i][--j] != '1')
	{
		isitem(&str[i][j]);
		if (str[i][j] == 'e')
			break ;
		if (str[i][j] == '0')
		{
			(*count)++;
			str[i][j] = '.';
		}
	}
}

int	line(char **str, int i, int j)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = j;
	while (str[i][++j] != '1')
	{
		isitem(&str[i][j]);
		if (str[i][j] == 'e')
			break ;
		if (str[i][j] == '0')
		{
			count++;
			str[i][j] = '.';
		}
	}
	j = tmp;
	line2(str, i, j, &count);
	return (count);
}
