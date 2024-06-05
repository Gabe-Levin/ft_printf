/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:34:20 by glevin            #+#    #+#             */
/*   Updated: 2024/06/04 19:24:52 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int dec, int is_upper)
{
	int	rem;
	int	stack[32];
	int	top;
	int	cnt;

	cnt = 0;
	top = -1;
	while (dec != 0)
	{
		rem = dec % 16;
		stack[++top] = rem;
		dec = dec / 16;
	}
	while (top >= 0)
	{
		rem = stack[top--];
		if (rem < 10)
			cnt += ft_putnbr(rem);
		else if (is_upper == 1)
			cnt += ft_putchar(rem + 55);
		else
			cnt += ft_putchar(rem + 87);
	}
	return (cnt);
}
