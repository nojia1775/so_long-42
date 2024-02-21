/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:54:24 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 12:55:47 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putun(unsigned int n, size_t *compt)
{
	long unsigned int	u;

	u = n;
	if (u >= 10)
	{
		ft_putun(u / 10, compt);
		ft_putun(u % 10, compt);
	}
	else
	{
		ft_putchar('0' + u);
		(*compt)++;
	}
}
