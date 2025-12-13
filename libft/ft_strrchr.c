/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:38:59 by dsalwa            #+#    #+#             */
/*   Updated: 2025/10/06 20:04:29 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*point;

	point = 0;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			point = ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (point);
}
