/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:57:14 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/08 12:01:21 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	prints(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printp(unsigned long l)
{
	int	len;

	len = prints("0x");
	len += printhex(l, 0);
	return (len);
}

int	printd(int i)
{
	int	len;

	ft_putnbr_fd(i, 1);
	len = 0;
	if (i <= 0)
		len++;
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

int	printu(unsigned int ui)
{
	int	len;

	len = 0;
	if (ui >= 10)
		len += printu(ui / 10);
	ui = ui % 10 + '0';
	write(1, &ui, 1);
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
	ui = ui % 16;
	write(1, hexset + ui, 1);
	return (len + 1);
}
