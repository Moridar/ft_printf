/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:07:09 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/08 12:01:27 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	convert(char c, va_list argptr);
int	printp(unsigned long l);
int	printd(int i);
int	printu(unsigned int ui);
int	printhex(unsigned long ui, int upper);
int	prints(char *str);

#endif