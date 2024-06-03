/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:33:50 by glevin            #+#    #+#             */
/*   Updated: 2024/06/03 15:38:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *p)
{
	int				rem;
	int				stack[32];
	int				top;
	unsigned long	dec;

	dec = (unsigned long)p;
	top = -1;
	while (dec != 0)
	{
		rem = dec % 16;
		stack[++top] = rem;
		dec = dec / 16;
	}
	write(1, "0x", 2);
	while (top >= 0)
	{
		rem = stack[top--];
		if (rem < 10)
			ft_putnbr_fd(rem, 1);
		else
			ft_putchar_fd(rem + 'a' - 10, 1);
	}
}
