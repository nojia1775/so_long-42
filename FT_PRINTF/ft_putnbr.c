/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:09:20 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 13:17:17 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, size_t *compt)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		*compt += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		(*compt)++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, compt);
		ft_putnbr(n % 10, compt);
	}
	else
	{
		(*compt)++;
		ft_putchar('0' + n);
	}
}
