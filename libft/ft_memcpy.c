/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:58:43 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/11 18:41:24 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ch;
	unsigned char	*s;

	ch = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*ch++ = *s++;
	}
	return (dest);
}
