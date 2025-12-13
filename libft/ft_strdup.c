/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:56:23 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/17 20:06:57 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	bites;
	size_t	index;
	char	*copy;

	bites = 0;
	index = 0;
	while (s[bites])
		bites++;
	copy = malloc(bites + 1);
	if (!copy)
		return (NULL);
	while (*s != '\0')
	{
		copy[index] = *s;
		index++;
		s++;
	}
	copy[index] = '\0';
	return (copy);
}
