/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:32:14 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 12:41:50 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(size_t n, size_t *compt, int *i)
{
	char	*base;

	if (n == 0 && *i == 0)
		return (0);
	if (*i == 0)
	{
		ft_putstr("0x");
		*compt += 2;
	}
	(*i)++;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_p(n / 16, compt, i);
		ft_p(n % 16, compt, i);
	}
	else
	{
		ft_putchar(base[n]);
		*compt += 1;
	}
	return (1);
}
