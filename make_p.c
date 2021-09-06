/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:19:02 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:19:20 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_p_itoa(long long int n, int base)
{
	unsigned long long	nb;
	static char			s[1024];
	char				*sim;
	size_t				len;

	sim = "0123456789abcdef";
	nb = n;
	ft_bzero(&s, 1024);
	len = ft_size(n, 16);
	if (nb < base)
	{
		s[0] = sim[nb % base];
		return (s);
	}
	else
	{
		while (len--)
		{
			*(s + len) = sim[nb % base];
			nb /= 16;
		}
	}
	return (s);
}

void	p_span(char *out, t_pars *pars)
{
	int		i;
	int		len;
	int		span;

	i = 0;
	len = ft_strlen(out);
	span = pars->span - len;
	if (pars->minus == 1)
	{
		i = len;
		while (i < pars->span)
			out[i++] = ' ';
	}
	else
	{
		ft_memmove(out + span, out, len);
		while (i < span)
			out[i++] = ' ';
	}
}

int		proc_p(va_list *vl, t_pars *pars)
{
	char				out[BUF_SIZE];
	unsigned long long	i;

	i = (unsigned long long)va_arg(*vl, void*);
	ft_bzero(&out, BUF_SIZE);
	ft_memcpy(out, "0x", 2);
	ft_memcpy(out + 2, ft_p_itoa(i, 16), ft_strlen(ft_p_itoa(i, 16)));
	if (pars->accuracy == 0 && i == 0)
	{
		ft_bzero(&out, BUF_SIZE);
		ft_memcpy(out, "0x", 2);
	}
	if (pars->span && pars->span > ft_strlen(out))
		p_span(out, pars);
	return (out_print(out));
}
