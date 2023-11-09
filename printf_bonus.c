/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:48:35 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/09 13:40:25 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	*initflags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (flags)
	{
		flags->leftjustify = 0;
		flags->width = 0;
		flags->precsion = 1;
		flags->hexsign = 0;
		flags->sign = 0;
		flags->space = 0;
		flags->zero = 0;
	}
	return (flags);
}

void	setnumber(const char **str, int *var, va_list argptr)
{
	if (**str == '.')
		(*str)++;
	if (**str == '*')
	{
		*var = va_arg(argptr, int);
		return ;
	}
	*var = ft_atoi(*str);
	while (ft_isdigit(*(*str + 1)))
		(*str)++;
}

int	checkflags(const char **str, va_list argptr)
{
	t_flags	*flags;

	flags = initflags();
	while (*(++*str))
	{
		if (**str == '0')
			flags->zero = 1;
		else if (**str == '-')
			flags->leftjustify = 1;
		else if (ft_isdigit(**str))
			setnumber(str, &flags->width, argptr);
		else if (**str == '.')
			setnumber(str, &flags->precsion, argptr);
		else if (**str == '#')
			flags->hexsign = 1;
		else if (**str == '+')
			flags->sign = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '*')
			flags->width = va_arg(argptr, int);
		else
			break ;
	}
	return (convert(**str, argptr, flags));
}

int	convert(char c, va_list argptr, t_flags *flags)
{
	if (c == '%')
		return (printc(c, flags));
	else if (c == 'c')
		return (printc(va_arg(argptr, int), flags));
	else if (c == 's')
		return (prints(va_arg(argptr, char *)));
	else if (c == 'p')
		return (printp((unsigned long)va_arg(argptr, void *)));
	else if (c == 'd' || c == 'i')
		return (printd(va_arg(argptr, int)));
	else if (c == 'u')
		return (printu(va_arg(argptr, unsigned int)));
	else if (c == 'x')
		return (printhex(va_arg(argptr, unsigned int), 0));
	else if (c == 'X')
		return (printhex(va_arg(argptr, unsigned int), 1));
	return (-1);
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
			checksum = checkflags(&str, argptr);
		if (checksum == -1)
			return (-1);
		i += checksum;
		str++;
	}
	va_end(argptr);
	return (i);
}
