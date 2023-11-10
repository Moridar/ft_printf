/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:53:40 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/10 19:06:37 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	printc(char c, t_flags *flags)
{
	int		len;
	char	*filling;

	if (flags->zero && !flags->leftjustify)
		filling = "0";
	else
		filling = " ";
	len = 0;
	if (flags->leftjustify && write(1, &c, 1) < 0)
		return (-1);
	while (flags->width > len++ + 1)
		if (write(1, filling, 1) < 0)
			return (-1);
	if (!flags->leftjustify && write(1, &c, 1) < 0)
		return (-1);
	return (len);
}

char	*checkprecsion(char *str, t_flags *flags)
{
	char	*zerostr;
	char	*newstr;
	int		n;
	int		sign;

	if (flags->precsion == 0 && *str == '0')
	{
		free(str);
		return (ft_strdup(""));
	}
	if (flags->precsion < 0 || flags->precsion < (int) ft_strlen(str))
		return (str);
	sign = 0;
	if (*str == '-' || *str == '+')
		sign = 1;
	n = flags->precsion - (int) ft_strlen(str + sign);
	zerostr = malloc(n + 1 + sign);
	zerostr[n + sign] = 0;
	ft_memset(zerostr + sign, '0', n);
	if (sign)
		zerostr[0] = *str;
	newstr = ft_strjoin(zerostr, str + sign);
	free(zerostr);
	free(str);
	return (newstr);
}

char	*checksign(char *str, t_flags *flags)
{
	char	*tmp;

	if (!flags->sign || *str == '-')
		return (str);
	tmp = str;
	str = ft_strjoin("+", str);
	free(tmp);
	return (str);
}

void	printflags(t_flags *flags)
{
	printf("leftjus: %d\nwidth: %d\nprec: %d\nhexsign: %d\nsign: %d\nspace: %d\nzero: %d\n",
		flags->leftjustify, flags->width, flags->precsion,
		flags->hexsign, flags->sign, flags->space, flags->zero);
}
