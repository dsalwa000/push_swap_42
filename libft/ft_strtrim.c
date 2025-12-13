/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:30:12 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/18 00:48:01 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_forward(const char *s1, const char *set)
{
	size_t	i;
	size_t	z;
	size_t	matched;

	i = 0;
	z = 0;
	while (s1[i])
	{
		matched = 0;
		while (set[z])
		{
			if (s1[i] == set[z])
			{
				i++;
				matched = 1;
				break ;
			}
			z++;
		}
		z = 0;
		if (matched == 0)
			break ;
	}
	return (i);
}

static size_t	count_backward(const char *s1, const char *set)
{
	size_t	j;
	size_t	z;
	size_t	matched;

	j = ft_strlen(s1) - 1;
	z = 0;
	while (s1[j])
	{
		matched = 0;
		while (set[z])
		{
			if (s1[j] == set[z])
			{
				j--;
				matched = 1;
				break ;
			}
			z++;
		}
		z = 0;
		if (matched == 0)
			break ;
	}
	return (j);
}

static char	*empty_array(void)
{
	char	*result;

	result = malloc(1);
	if (!result)
		return (NULL);
	return (result[0] = '\0', result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char		*our_return;
	long int	ptr_diff;
	size_t		i;
	size_t		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (result = empty_array(), result);
	i = count_forward(s1, set);
	j = count_backward(s1, set);
	ptr_diff = j - i + 1;
	if (ptr_diff <= 0)
		return (result = empty_array(), result);
	result = malloc(ptr_diff + 1);
	if (!result)
		return (NULL);
	our_return = result;
	while (j >= i)
		*result++ = s1[i++];
	*result = '\0';
	return (our_return);
}
