/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:19:37 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:20:02 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	num;
	long int		len;
	char			*s;
	unsigned int	i;

	num = n;
	if (n < 0)
		num = -n;
	i = 0;
	len = ft_numbers_count(n);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		s[i++] = '-';
	s[len--] = '\0';
	while (len >= i)
	{
		s[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (s);
}

void	u_accur(char *out, t_pars *pars)
{
	int		i;
	int		len;
	int		span;

	len = ft_strlen(out);
	span = pars->accuracy - len;
	i = 0;
	ft_memmove(out + span, out, len);
	while (i < span)
		out[i++] = '0';
}

void	u_span(char *out, t_pars *pars)
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

void	u_span_0(char *out, t_pars *pars)
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
			out[i++] = '0';
	}
}

int		proc_u(va_list *vl, t_pars *pars)
{
	char			out[BUF_SIZE];
	unsigned int	i;
	char			*tmp;

	i = va_arg(*vl, int);
	tmp = ft_u_itoa(i);
	ft_bzero(out, BUF_SIZE);
	ft_memcpy(out, tmp, ft_strlen(tmp));
	free(tmp);
	if (pars->accuracy == 0 && i == 0)
		ft_bzero(&out, BUF_SIZE);
	if (pars->accuracy >= 0 && pars->accuracy > ft_strlen(out))
		u_accur(out, pars);
	if (pars->accuracy < 0 && pars->span > ft_strlen(out) && pars->zero)
		u_span_0(out, pars);
	if (pars->span && pars->span > ft_strlen(out))
		u_span(out, pars);
	return (out_print(out));
}
