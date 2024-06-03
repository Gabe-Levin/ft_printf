/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:10 by glevin            #+#    #+#             */
/*   Updated: 2024/06/03 15:38:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdec(double n, int fd)
{
	int		int_value;
	double	decimal;
	int		digit;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	int_value = (int)n;
	decimal = n - (double)int_value;
	ft_putnbr_fd(int_value, fd);
	if (decimal == 0)
		return ;
	ft_putchar_fd('.', 1);
	while (decimal != 0)
	{
		decimal *= 10;
		digit = (int)decimal;
		ft_putchar_fd(digit + '0', fd);
		decimal -= digit;
		if (decimal < 1e-9)
			break ;
	}
}
