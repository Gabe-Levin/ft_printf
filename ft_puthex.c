/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:34:20 by glevin            #+#    #+#             */
/*   Updated: 2024/06/03 15:38:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(int dec, int is_upper)
{
	int	rem;
	int	stack[32];
	int	top;

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
			ft_putnbr_fd(rem, 1);
		else if (is_upper == 1)
			ft_putchar_fd(rem + 55, 1);
		else
			ft_putchar_fd(rem + 87, 1);
	}
}
