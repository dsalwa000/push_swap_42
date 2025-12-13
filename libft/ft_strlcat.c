/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:37:30 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/17 19:58:04 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	slength;
	size_t	dlength;

	index = 0;
	slength = ft_strlen(src);
	dlength = ft_strlen(dst);
	if (size == 0)
		return (slength);
	if (dlength >= size)
		return (size + slength);
	while (src[index] != '\0' && index + dlength < size - 1)
	{
		dst[index + dlength] = src[index];
		index++;
	}
	dst[index + dlength] = '\0';
	return (slength + dlength);
}
