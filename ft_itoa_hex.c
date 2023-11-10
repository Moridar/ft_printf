/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:28:02 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/10 17:27:43 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	nlen(unsigned long n, int base)
{
	int				i;
	unsigned long	res;

	i = 1;
	res = base;
	while (res <= n)
	{
		i++;
		if (res > res * base)
			break ;
		res *= base;
	}
	return (i);
}

char	*ft_itoa_hex(unsigned long n, int upper)
{
	char	*str;
	int		i;
	char	*hexset;

	if (upper)
		hexset = "0123456789ABCDEF";
	else
		hexset = "0123456789abcdef";
	i = nlen(n, 16) + 1;
	str = malloc(i--);
	if (!str)
		return (0);
	str[i--] = 0;
	while (i >= 0)
	{
		str[i--] = hexset[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned long n)
{
	char	*str;
	int		i;

	i = nlen(n, 10) + 1;
	str = malloc(i--);
	if (!str)
		return (0);
	str[i--] = 0;
	while (i >= 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}