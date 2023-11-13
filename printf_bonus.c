/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:48:35 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/13 13:35:40 by bsyvasal         ###   ########.fr       */
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
		flags->precsion = -1;
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
	if (!ft_isdigit(**str))
	{
		--*str;
		return ;
	}
	while (ft_isdigit(*(*str + 1)))
		(*str)++;
}

int	checkflags(const char **str, va_list argptr, t_flags *flags)
{
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
	return (convert(str, argptr, flags));
}

int	convert(const char **str, va_list argptr, t_flags *flags)
{
	char	c;

	c = **str;
	if (c == '%')
		return (printc(c, flags));
	if (c == 'c')
		return (printc(va_arg(argptr, int), flags));
	if (c == 's')
		return (prints(va_arg(argptr, char *), flags));
	if (c == 'p')
		return (printp((unsigned long)va_arg(argptr, void *), flags));
	if (c == 'd' || c == 'i')
		return (printd(va_arg(argptr, int), flags));
	if (c == 'u')
		return (printu(va_arg(argptr, unsigned int), flags));
	if (c == 'x')
		return (printhex(va_arg(argptr, unsigned int), 0, flags));
	if (c == 'X')
		return (printhex(va_arg(argptr, unsigned int), 1, flags));
	--*str;
	return (-2);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		checksum;
	t_flags	*flags;

	va_start(argptr, str);
	i = 0;
	while (*str)
	{
		if (*str != '%')
			checksum = write(1, str, 1);
		else
		{
			flags = initflags();
			checksum = checkflags(&str, argptr, flags);
			free(flags);
		}
		if (checksum == -1)
			return (-1);
		if (checksum >= 0)
			i += checksum;
		str++;
	}
	va_end(argptr);
	return (i);
}
