/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:22:52 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:23:49 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_span(char *out, t_pars *pars)
{
	int		i;
	int		span;
	int		l;
	int		sum;

	i = 0;
	l = ft_strlen(out);
	span = pars->span;
	sum = span - l;
	if (pars->minus == 1)
	{
		i = l;
		while (i < pars->span)
			out[i++] = ' ';
		out[i] = '\0';
	}
	else
	{
		ft_memmove(out + sum, out, l);
		out[span] = '\0';
		while (sum--)
			*out++ = ' ';
	}
}

int		proc_s(va_list *vl, t_pars *pars)
{
	char	*tmp;
	char	out[BUF_SIZE];

	ft_bzero(out, BUF_SIZE);
	if (!(tmp = va_arg(*vl, char*)))
		ft_memcpy(out, "(null)", ft_strlen("(null)"));
	else
		ft_memcpy(out, tmp, ft_strlen(tmp));
	if (pars->accuracy >= 0 && pars->accuracy < ft_strlen(out))
		out[pars->accuracy] = '\0';
	if (pars->span && pars->span > ft_strlen(out))
		s_span(out, pars);
	return (out_print(out));
}
