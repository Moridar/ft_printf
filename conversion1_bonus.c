/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:53:40 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/09 14:03:31 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	free(flags);
	return (len);
}
