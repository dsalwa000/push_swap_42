/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:07:58 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/19 12:32:10 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;

	if (nmemb > SIZE_MAX / size && size != 0)
		return (NULL);
	memory = (unsigned char *)malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
