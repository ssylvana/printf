/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 21:02:36 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/27 21:03:00 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strb, const char *stra, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!(*stra))
		return (char*)(strb);
	while (strb[i] && i < len)
	{
		j = 0;
		while (stra[j] && (i + j) < len)
		{
			if (strb[i + j] != stra[j])
				break ;
			j++;
		}
		if (!stra[j])
			return (char*)&(strb[i]);
		i++;
	}
	return (0);
}
