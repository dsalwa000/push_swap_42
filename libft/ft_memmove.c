/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:40:23 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/11 17:22:06 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
	{
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n > i)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
