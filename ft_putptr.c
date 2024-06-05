/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:33:50 by glevin            #+#    #+#             */
/*   Updated: 2024/06/04 19:26:11 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int				rem;
	int				stack[32];
	int				top;
	unsigned long	dec;
	int				cnt;

	cnt = 0;
	dec = (unsigned long)p;
	top = -1;
	while (dec != 0)
	{
		rem = dec % 16;
		stack[++top] = rem;
		dec = dec / 16;
	}
	cnt += ft_putstr("0x");
	while (top >= 0)
	{
		rem = stack[top--];
		if (rem < 10)
			cnt += ft_putnbr(rem);
		else
			cnt += ft_putchar(rem + 'a' - 10);
	}
	return (cnt);
}
