/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:48:35 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/08 12:49:34 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert(char c, va_list argptr)
{
	if (c == '%')
		return (write(1, &c, 1));
	else if (c == 'c')
		ft_putchar_fd(va_arg(argptr, int), 1);
	else if (c == 's')
		return (prints(va_arg(argptr, char *)));
	else if (c == 'p')
		return (printp(va_arg(argptr, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (printd(va_arg(argptr, int)));
	else if (c == 'u')
		return (printu(va_arg(argptr, unsigned int)));
	else if (c == 'x')
		return (printhex(va_arg(argptr, unsigned int), 0));
	else if (c == 'X')
		return (printhex(va_arg(argptr, unsigned int), 1));
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		checksum;

	va_start(argptr, str);
	i = 0;
	while (*str)
	{
		if (*str != '%')
			checksum = write(1, str, 1);
		else
			checksum = convert(*(++str), argptr);
		if (checksum == -1)
			return (-1);
		i += checksum;
		str++;
	}
	va_end(argptr);
	return (i);
}
