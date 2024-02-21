/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:27 by nadjemia          #+#    #+#             */
/*   Updated: 2023/11/22 15:12:58 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_leane_1(char c, va_list args, size_t *compt);
static int		ft_leane_2(char c, va_list args, size_t *compt);
static int		ft_leane_3(char c, va_list args, size_t *compt);
static size_t	ft_format(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	compt;

	if (!format)
		return (-1);
	va_start(args, format);
	compt = ft_format(format, args);
	va_end(args);
	return (compt);
}

static int	ft_leane_1(char c, va_list args, size_t *compt)
{
	const char	*str;

	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		(*compt)++;
	}
	else if (c == 's')
	{
		str = va_arg(args, const char *);
		if (str == NULL)
		{
			ft_putstr("(null)");
			*compt += 6;
			return (1);
		}
		ft_putstr(str);
		*compt += ft_strlen(str);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), compt);
	else
		return (0);
	return (1);
}

static int	ft_leane_2(char c, va_list args, size_t *compt)
{
	if (c == '%')
	{
		ft_putchar('%');
		(*compt)++;
	}
	else if (c == 'u')
		ft_putun(va_arg(args, unsigned int), compt);
	else
		return (0);
	return (1);
}

static int	ft_leane_3(char c, va_list args, size_t *compt)
{
	int	i;

	i = 0;
	if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ft_putnbr_m((long long unsigned int)va_arg(args, unsigned int),
				compt, "0123456789abcdef");
		else
			ft_putnbr_m((long long unsigned int)va_arg(args, unsigned int),
				compt, "0123456789ABCDEF");
	}
	else if (c == 'p')
	{
		if (!(ft_p(va_arg(args, size_t), compt, &i)))
		{
			ft_putstr("(nil)");
			*compt += 5;
			return (1);
		}
	}
	else
		return (0);
	return (1);
}

static size_t	ft_format(const char *format, va_list args)
{
	int		i;
	size_t	compt;

	compt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_leane_1(format[i + 1], args, &compt)
				|| ft_leane_2(format[i + 1], args, &compt)
				|| ft_leane_3(format[i + 1], args, &compt))
				i += 2;
			else
				return (-1);
		}
		else
		{
			ft_putchar(format[i]);
			compt++;
			i++;
		}
	}
	return (compt);
}
