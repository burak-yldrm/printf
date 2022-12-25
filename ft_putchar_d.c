/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyildir <buyildir@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:34:13 by buyildir          #+#    #+#             */
/*   Updated: 2022/06/05 10:34:15 by buyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		a = -a;
	while (a)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	ft_putchar_d(int a)
{
	int	len;

	len = ft_count(a);
	if (a == -2147483648)
	{
		len += ft_putchar('-');
		ft_putchar('2');
		a = 147483648;
	}
	if (a < 0)
	{
		a = a * -1;
		len += ft_putchar('-');
	}
	if (a < 10)
	{
		ft_putchar(a + '0');
		return (len);
	}
	else
	{
		ft_putchar_d(a / 10);
	}
	ft_putchar_d(a % 10);
	return (len);
}
