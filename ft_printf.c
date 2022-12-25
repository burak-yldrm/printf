/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyildir <buyildir@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:33:41 by buyildir          #+#    #+#             */
/*   Updated: 2022/06/05 10:33:43 by buyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_form(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putchar_s(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_putchar_p(va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putchar_d(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putchar_u(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putchar_x(va_arg(arg, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_form(arg, str[i++]);
		}
		else
			len += ft_putchar(str[i++]);
	}
	va_end(arg);
	return (len);
}
