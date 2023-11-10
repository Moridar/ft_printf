/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:51:37 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/10 13:20:33 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(size_t n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p > 1)
		return (n * ft_power(n, p - 1));
	return (n);
}
