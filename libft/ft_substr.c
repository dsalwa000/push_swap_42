/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:52:59 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/17 20:39:30 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	target_size;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	target_size = 0;
	if (start < slen)
	{
		target_size = ft_strlen(s + start);
		if (target_size > len)
			target_size = len;
	}
	sub = (char *)malloc(target_size + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < target_size)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub[i] = '\0', sub);
}
