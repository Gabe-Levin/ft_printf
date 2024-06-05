/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:10 by glevin            #+#    #+#             */
/*   Updated: 2024/06/04 20:06:18 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(double n)
{
	double		decimal;
	int			digit;
	int			cnt;
	long long	int_part;

	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n = -n;
	}
	int_part  =(long long)n;
	decimal = n - (double)n;
	cnt += ft_putnbr((double)n);
	if (decimal == 0)
		return (cnt);
	cnt += ft_putchar('.');
	while (decimal != 0)
	{
		decimal *= 10;
		digit = (int)decimal;
		cnt += ft_putchar(digit + '0');
		decimal -= digit;
		if (decimal < 1e-9)
			break ;
	}
	return (cnt);
}
