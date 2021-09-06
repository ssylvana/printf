/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:21:18 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:21:43 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		out_print(char *out)
{
	static int	bytes_read;

	bytes_read = 0;
	while (out && *out)
		bytes_read += write(1, out++, 1);
	return (bytes_read);
}

void	ft_struct(t_pars *pars)
{
	pars->minus = 0;
	pars->span = 0;
	pars->accuracy = -1;
	pars->zero = 0;
}

int		ft_printf(const char *s, ...)
{
	char		*str;
	va_list		vl;
	t_pars		pars;
	int			rtrn;

	va_start(vl, s);
	str = (char*)s;
	rtrn = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			rtrn += parser(&str, &vl, &pars);
		else
		{
			rtrn += ft_putchar(*str);
			str++;
		}
	}
	va_end(vl);
	return (rtrn);
}
