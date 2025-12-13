/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:10:45 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/11 17:26:07 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sh = (const unsigned char *)s;
	unsigned char		ch;

	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*sh == ch)
			return ((void *)sh);
		n--;
		sh++;
	}
	return (0);
}
