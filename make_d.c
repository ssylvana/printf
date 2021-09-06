/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:22:07 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:22:27 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_accur(char *out, t_pars *pars, int flag)
{
	int		i;
	int		len;
	int		span;

	len = ft_strlen(out);
	span = pars->accuracy - len;
	if (flag > 0)
		span = pars->accuracy - len + 1;
	i = 0;
	ft_memmove(out + span, out, len);
	if (flag > 0)
		span++;
	while (i < span)
		out[i++] = '0';
	if (flag == 1)
		out[0] = '-';
}

void	d_span(char *out, t_pars *pars, int flag)
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
		out[i] = '\0';
	}
	else
	{
		ft_memmove(out + span, out, len);
		while (i < span)
			out[i++] = ' ';
	}
}

void	d_span_0(char *out, t_pars *pars, int flag)
{
	int		i;
	int		len;
	int		span;

	i = 0;
	len = ft_strlen(out);
	span = pars->span - len;
	if (pars->minus == 1)
	{
		i = (flag == 1 ? len + 1 : len);
		while (i < pars->span)
			out[i++] = ' ';
		if (flag == 1)
			out[0] = '-';
	}
	else
	{
		ft_memmove(out + span, out, len);
		span = (flag > 0 ? span + 1 : span);
		while (i < span)
			out[i++] = '0';
		if (flag == 1)
			out[0] = '-';
	}
}

int		proc_d(va_list *vl, t_pars *pars)
{
	char			out[BUF_SIZE];
	char			*tmp;
	int				flag;
	long long int	i;

	flag = 0;
	i = va_arg(*vl, int);
	tmp = ft_itoa(i);
	if (i < 0)
		flag = 1;
	ft_bzero(&out, BUF_SIZE);
	ft_memcpy(out, tmp, ft_strlen(tmp));
	free(tmp);
	if (pars->accuracy == 0 && i == 0)
		ft_bzero(&out, 1024);
	if (pars->accuracy > 0 && pars->accuracy >= ft_strlen(out))
		d_accur(out, pars, flag);
	if (pars->accuracy < 0 && pars->span > ft_strlen(out) && pars->zero)
		d_span_0(out, pars, flag);
	if (pars->span && pars->span > ft_strlen(out))
		d_span(out, pars, flag);
	return (out_print(out));
}
