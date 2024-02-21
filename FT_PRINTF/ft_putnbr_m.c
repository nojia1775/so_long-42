/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:52:42 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 15:14:07 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_m(long long unsigned int n, size_t *compt, char *base)
{
	long long unsigned int	base_len;

	base_len = 16;
	if (n >= base_len)
	{
		ft_putnbr_m(n / base_len, compt, base);
		ft_putnbr_m(n % base_len, compt, base);
	}
	else
	{
		ft_putchar(base[n]);
		(*compt)++;
	}
}
