/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:29:47 by tschulle          #+#    #+#             */
/*   Updated: 2024/11/18 18:00:12 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_conversion(const char *str, va_list args);
int		ft_puthex_low(unsigned int n);
int		ft_puthex_up(unsigned int n);
int		ft_putnbr_fd_long(unsigned int n, int fd);
int		ft_putstr_fd_mod(char *s, int fd);
int		ft_putnbr_fd_mod(int n, int fd);
int		ft_putnbr_fd_mod_outsource(int n, int fd);
int		ft_putchar_fd_mod(char c, int fd);
int		ft_putpointer(va_list args);
int		ft_puthex_p(unsigned long i);

#endif