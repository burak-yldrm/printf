/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buyildir <buyildir@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:34:50 by buyildir          #+#    #+#             */
/*   Updated: 2022/06/05 10:34:51 by buyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long long a)
{
	if (a >= 16)
	{
		ft_puthex(a / 16);
		ft_puthex(a % 16);
	}
	else
	{
		if (a <= 9)
			ft_putchar(a + '0');
		else
			ft_putchar((a - 10) + 'a');
	}
}
