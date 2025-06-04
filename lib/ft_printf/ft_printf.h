/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:20:07 by mariaber          #+#    #+#             */
/*   Updated: 2025/01/21 14:14:19 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_print_format(const char c, va_list args, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_check(int n, int *count);
void	ft_checkzero(int n, int *count);
void	ft_putnbr(unsigned int n, int *count);
int		ft_countnum(unsigned int n);
void	ft_puthex(unsigned int num, int *count, const char c);
void	ft_putpntr(void *num, int *count);
void	ft_puthexp(unsigned long long n, int *count);

#endif
