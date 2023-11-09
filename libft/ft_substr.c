/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:08:10 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/11/06 09:40:53 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	strlen = ft_strlen(s + start);
	if (strlen < len)
		len = strlen;
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
