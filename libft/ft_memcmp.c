/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:14:06 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/11 17:27:45 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sh1;
	const unsigned char	*sh2;

	sh1 = (const unsigned char *)s1;
	sh2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*sh1 != *sh2)
			return ((int)*sh1 - (int)*sh2);
		sh1++;
		sh2++;
	}
	return (0);
}
