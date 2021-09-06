/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:04:08 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/24 17:56:27 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen((char*)s1);
	b = ft_strlen((char*)s2);
	if (!(s3 = malloc((a + b + 2) * sizeof(char))))
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		s3[a] = s1[a];
		a++;
	}
	c = 0;
	while (s2[c] != '\0')
	{
		s3[a++] = s2[c];
		c++;
	}
	s3[a] = '\0';
	return (s3);
}
