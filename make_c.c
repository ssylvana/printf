/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:18:09 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:18:43 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_span_minus(char c, t_pars *pars)
{
	int		ret;
	int		span;

	ret = 0;
	span = pars->span;
	ret += ft_putchar(c);
	while ((--span) > 0)
		ret += ft_putchar(' ');
	return (ret);
}

int		c_span(char c, t_pars *pars)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	pars->span -= 1;
	while (i < pars->span)
	{
		if (pars->zero == 1)
			ret += ft_putchar('0');
		else
			ret += ft_putchar(' ');
		i++;
		if (i == pars->span)
		{
			ft_putchar(c);
			ret++;
		}
	}
	return (ret);
}

int		proc_c(va_list *vl, t_pars *pars, char **str)
{
	char	c;

	if (**str == '%')
		c = **str;
	else
		c = va_arg(*vl, int);
	if (pars->span > 1 && pars->minus)
		return (c_span_minus(c, pars));
	else if (pars->span > 1 && !pars->minus)
		return (c_span(c, pars));
	else
		return (write(1, &c, 1));
}
