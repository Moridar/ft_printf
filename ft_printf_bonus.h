/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:07:09 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/09 13:04:52 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	leftjustify;
	int	width;
	int	precsion;
	int	hexsign;
	int	sign;
	int	space;
	int	zero;
}		t_flags;
int	ft_printf(const char *str, ...);
int	convert(char c, va_list argptr, t_flags *flags);
int	printp(unsigned long l);
int	printd(int i);
int	printu(unsigned int ui);
int	printhex(unsigned long ui, int upper);
int	prints(char *str);
int	printc(char c, t_flags *flags);

#endif