/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:04:00 by ssylvana          #+#    #+#             */
/*   Updated: 2020/11/24 23:02:52 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_zero(char *s, int count2)
{
	if (s[0] == '-')
		s[count2 + 1] = '\0';
	else
		s[count2] = '\0';
	return (s);
}

static int			ft_number(int n)
{
	int	count;
	int	ncopy;

	ncopy = n;
	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void			*ft_zap(char *s, int count, int n)
{
	unsigned int	sig_n;
	int				count2;

	count2 = count;
	if (n < 0)
	{
		sig_n = n * -1;
		while (count > 0)
		{
			s[count] = sig_n % 10 + '0';
			sig_n = sig_n / 10;
			count--;
		}
		s[0] = '-';
	}
	else
	{
		while (count-- > 0)
		{
			s[count] = n % 10 + '0';
			n = n / 10;
		}
	}
	ft_zero(s, count2);
	return (s);
}

char				*ft_itoa(int n)
{
	int				count;
	char			*s;

	count = ft_number(n);
	if (n > 0)
	{
		s = malloc((count + 1) * sizeof(char));
		if (s == (NULL))
			return (NULL);
	}
	else if (n < 0)
	{
		s = malloc((count + 2) * sizeof(char));
		if (s == (NULL))
			return (NULL);
	}
	else
	{
		s = malloc(2);
		if (s == (NULL))
			return (NULL);
	}
	s = ft_zap(s, count, n);
	return (s);
}
