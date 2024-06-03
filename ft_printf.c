/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:59:44 by glevin            #+#    #+#             */
/*   Updated: 2024/06/03 15:58:12 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			char_value;
	char			*str_value;
	int				i_value;
	double			fl_value;
	unsigned int	udec_val;
	void			*p;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char_value = (char)va_arg(args, int);
				ft_putchar_fd(char_value, 1);
			}
			else if (*format == 's')
			{
				str_value = va_arg(args, char *);
				ft_putstr_fd(str_value, 1);
			}
			else if (*format == 'd')
			{
				fl_value = va_arg(args, double);
				ft_putdec(fl_value, 1);
			}
			else if (*format == 'i')
			{
				i_value = va_arg(args, int);
				ft_putnbr_fd(i_value, 1);
			}
			else if (*format == 'u')
			{
				udec_val = va_arg(args, unsigned int);
				ft_putdec(udec_val, 1);
			}
			else if (*format == 'x')
			{
				udec_val = va_arg(args, unsigned int);
				ft_puthex(udec_val, 0);
			}
			else if (*format == 'X')
			{
				udec_val = va_arg(args, unsigned int);
				ft_puthex(udec_val, 1);
			}
			else if (*format == 'p')
			{
				p = va_arg(args, void *);
				ft_putptr(p);
			}
			else if (*format == '%')
			{
				udec_val = va_arg(args, int);
				ft_putchar_fd('%', 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (-1);
}

// void	main(void)
// {
// 	int number = 1231234;
// 	int *ptr = &number;
// 	printf("og_printf: test %p\n", (void *)ptr);
// 	ft_printf("og_printf: test %p\n", (void *)ptr);
// 	// printf("og_printf: test %x\n", 1234567);
// 	// ft_printf("ft_printf: test %X\n", 123123454);
// }