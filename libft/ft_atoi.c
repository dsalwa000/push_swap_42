/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:29:46 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/19 12:28:25 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	positive;
	int	multiplier;
	int	count;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	positive = 1;
	multiplier = 10;
	count = 0;
	if (*nptr == '-')
	{
		positive = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr != '\0')
	{
		if (*nptr < '0' || *nptr > '9')
			return (count * positive);
		count = count * multiplier + (*nptr - 48);
		nptr++;
	}
	return (count * positive);
}
