/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:22:44 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/17 17:02:23 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_positive(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	int_length(int n)
{
	int	length;

	if (n == INT_MIN)
		return (11);
	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	set_first_number(int *n, int *length, char **result,
		int is_positive)
{
	if (*n == INT_MIN)
	{
		(*result)[(*length)--] = '8';
		*n = ((*n + 1) * is_positive / 10);
	}
	else
		*n *= is_positive;
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;
	int		is_positive;

	is_positive = check_positive(n);
	length = int_length(n);
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	result[length--] = '\0';
	set_first_number(&n, &length, &result, is_positive);
	while (length >= 0)
	{
		if (length == 0 && is_positive == -1)
			result[length--] = '-';
		else
		{
			result[length--] = (n % 10) + 48;
			n /= 10;
		}
	}
	return (result);
}
