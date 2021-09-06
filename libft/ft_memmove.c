/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:12:22 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/24 16:18:46 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	int				i;

	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	i = 0;
	if (!len || src == dst)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i--)
			dest[i] = sorc[i];
	}
	else
	{
		while (len--)
			*dest++ = *sorc++;
	}
	return (dst);
}
