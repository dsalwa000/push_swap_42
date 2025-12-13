/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:41:59 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/11 17:22:57 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ch;

	ch = (unsigned char *)s;
	while (n--)
	{
		*ch = (unsigned char)c;
		ch++;
	}
	return (s);
}
