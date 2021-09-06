/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:20:38 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:20:52 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pars_accuracy(char **str, va_list *vl)
{
	int	sum;

	(*str)++;
	sum = 0;
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
		{
			sum = (sum * 10) + (**str - '0');
			(*str)++;
		}
	}
	else if (**str == '*')
	{
		(*str)++;
		return (va_arg(*vl, int));
	}
	else
		return (0);
	return (sum);
}

int		pars_span(char **str, va_list *vl)
{
	int sum;

	sum = 0;
	if (**str == '*')
	{
		(*str)++;
		return (va_arg(*vl, int));
	}
	else if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
		{
			sum = (sum * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (sum);
}

void	pars_flags(char **str, va_list *vl, t_pars *pars)
{
	while (**str == '0' || **str == '-' || **str == '*' || ft_isdigit(**str) ||
			**str == '.')
	{
		if (**str == '0')
			pars->zero = 1;
		else if (**str == '-')
			pars->minus = 1;
		else if (ft_isdigit(**str) || **str == '*')
		{
			pars->span = pars_span(str, vl);
			continue;
		}
		else if (**str == '.')
		{
			pars->accuracy = pars_accuracy(str, vl);
			continue;
		}
		(*str)++;
	}
	if (pars->span < 0)
	{
		pars->minus = 1;
		pars->span *= -1;
	}
}

int		pars_types(char **str, va_list *vl, t_pars *pars)
{
	int		ret;

	if (**str == 's')
		ret = proc_s(vl, pars);
	else if (**str == 'x' || **str == 'X')
		ret = proc_x(vl, pars, **str);
	else if (**str == 'c' || **str == '%')
		ret = proc_c(vl, pars, str);
	else if (**str == 'd' || **str == 'i')
		ret = proc_d(vl, pars);
	else if (**str == 'p')
		ret = proc_p(vl, pars);
	else if (**str == 'u')
		ret = proc_u(vl, pars);
	else
		return (0);
	(*str)++;
	return (ret);
}

int		parser(char **str, va_list *vl, t_pars *pars)
{
	(*str)++;
	ft_struct(pars);
	pars_flags(str, vl, pars);
	return (pars_types(str, vl, pars));
}
