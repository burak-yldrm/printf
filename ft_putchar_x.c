/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyildir <buyildir@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:34:41 by buyildir          #+#    #+#             */
/*   Updated: 2022/06/05 10:34:42 by buyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static void	ft_uplow(unsigned int a, int c)
{
	if (c == 'X')
		ft_putchar((a - 10) + 'A');
	else
		ft_putchar((a - 10) + 'a');
}

int	ft_putchar_x(unsigned int a, int c)
{
	int	len;

	len = ft_count(a);
	if (a == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	else
	{
		if (a >= 16)
		{
			ft_putchar_x((a / 16), c);
			ft_putchar_x((a % 16), c);
		}
		else
		{
			if (a <= 9)
				ft_putchar(a + '0');
			else
				ft_uplow(a, c);
		}
	}
	return (len);
}
