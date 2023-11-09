/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:57:14 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/09 12:54:18 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	prints(char *str)
{
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

int	printp(unsigned long l)
{
	int	len;

	len = write(1, "0x", 2);
	if (len < 0)
		return (-1);
	len += printhex(l, 0);
	return (len);
}

int	printd(int i)
{
	int		len;
	char	*str;

	str = ft_itoa(i);
	if (!str)
		return (-1);
	len = prints(str);
	free(str);
	return (len);
}

int	printu(unsigned int ui)
{
	int	len;

	len = 0;
	if (ui >= 10)
		len += printu(ui / 10);
	if (len < 0)
		return (-1);
	ui = ui % 10 + '0';
	if (write(1, &ui, 1) < 0)
		return (-1);
	return (1 + len);
}

int	printhex(unsigned long ui, int upper)
{
	char	*hexset;
	int		len;

	len = 0;
	if (upper)
		hexset = "0123456789ABCDEF";
	else
		hexset = "0123456789abcdef";
	if (ui >= 16)
		len += printhex(ui / 16, upper);
	if (len < 0)
		return (-1);
	ui = ui % 16;
	if (write(1, hexset + ui, 1) < 0)
		return (-1);
	return (len + 1);
}
