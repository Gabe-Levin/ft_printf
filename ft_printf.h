/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:18 by glevin            #+#    #+#             */
/*   Updated: 2024/06/03 15:58:04 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putdec(double n, int fd);
void	ft_puthex(int dec, int is_upper);
void	ft_putnbr_fd(int n, int fd);
void	ft_putptr(void *p);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
