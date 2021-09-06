/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:47:55 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/24 17:18:13 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	int				i;
	unsigned int	countstr;

	if (s == (NULL))
		return (NULL);
	i = 0;
	countstr = ft_strlen((char*)s);
	s1 = malloc((countstr + 1) * sizeof(char));
	if (s1 == (NULL))
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
