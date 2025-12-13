/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:16:14 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/17 21:20:29 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_arrays(const char *s, char c)
{
	size_t	single_size;
	size_t	amount;
	size_t	i;

	single_size = 0;
	amount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			single_size++;
		if (s[i] == c && single_size > 0)
		{
			amount++;
			single_size = 0;
		}
		i++;
	}
	if (single_size > 0)
		amount++;
	return (amount);
}

static size_t	string_length(const char **s, char c)
{
	size_t	size;

	size = 0;
	while (**s == c && **s != '\0')
		(*s)++;
	while (**s != c && **s != '\0')
	{
		size++;
		(*s)++;
	}
	return (size);
}

static char	**allocate_memory(const char *s, char c)
{
	char	**result;
	size_t	str_len;
	size_t	i;

	result = (char **)ft_calloc(count_arrays(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	str_len = 0;
	while (*s != '\0')
	{
		str_len = string_length(&s, c);
		if (str_len == 0)
			break ;
		result[i] = (char *)ft_calloc(str_len + 1, sizeof(char));
		if (!result[i++])
			return (result);
	}
	result[i] = NULL;
	return (result);
}

static void	fill_string(char *str, const char **s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (**s == c)
		(*s)++;
	while (**s && **s != c)
	{
		str[i++] = **s;
		size++;
		(*s)++;
	}
	if (size > 0)
		str[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	count_allocated;

	if (!s)
		return (NULL);
	result = allocate_memory(s, c);
	if (!result)
		return (NULL);
	i = 0;
	count_allocated = 0;
	while (result[i++] != NULL)
		count_allocated++;
	if (count_allocated != count_arrays(s, c))
	{
		while (count_allocated > 0)
			free(result[count_allocated-- - 1]);
		free(result);
		return (NULL);
	}
	i = 0;
	while (result[i] != NULL)
		fill_string(result[i++], &s, c);
	return (result);
}
