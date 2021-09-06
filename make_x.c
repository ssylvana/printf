/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:24:09 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:24:26 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numbers_count(unsigned long long int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_size(unsigned long long numb, int base)
{
	size_t	ln;

	ln = 0;
	if (numb == 0)
		return (1);
	while (numb)
	{
		numb /= base;
		ln++;
	}
	return (ln);
}

void	do_upper(char *out)
{
	int		i;

	i = 0;
	while (out[i] != '\0')
	{
		if (out[i] >= 97 && out[i] <= 122)
			out[i] = out[i] - 32;
		i++;
	}
}

int		proc_x(va_list *vl, t_pars *pars, char x)
{
	char			out[BUF_SIZE];
	unsigned int	i;

	i = va_arg(*vl, int);
	ft_bzero(out, BUF_SIZE);
	ft_memcpy(out, ft_p_itoa(i, 16), ft_strlen(ft_p_itoa(i, 16)));
	if (pars->accuracy == 0 && i == 0)
		ft_bzero(&out, BUF_SIZE);
	if (pars->accuracy >= 0 && pars->accuracy > ft_strlen(out))
		u_accur(out, pars);
	if (pars->accuracy < 0 && pars->span > ft_strlen(out) && pars->zero)
		u_span_0(out, pars);
	if (pars->span && pars->span > ft_strlen(out))
		u_span(out, pars);
	if (x == 'X')
		do_upper(out);
	return (out_print(out));
}
