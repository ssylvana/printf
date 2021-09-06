/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:45:17 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/24 16:09:47 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	if (!n || (src == dst))
		return (dst);
	while (n--)
	{
		*dest++ = *sorc++;
	}
	return (dst);
}
