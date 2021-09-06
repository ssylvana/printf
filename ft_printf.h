/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:16:37 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/26 18:17:47 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUF_SIZE
#  define BUF_SIZE 1024 * 1024
# endif

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_pars
{
	int			minus;
	int			zero;
	int			span;
	int			accuracy;
}				t_pars;

int				ft_printf(const char *s, ...);
void			ft_struct(t_pars *pars);
char			*ft_p_itoa(long long int n, int base);
size_t			ft_size(unsigned long long numb, int base);
int				pars_accuracy(char **str, va_list *vl);
int				pars_span(char **str, va_list *vl);
void			pars_flags(char **str, va_list *vl, t_pars *pars);
int				pars_types(char **str, va_list *vl, t_pars *pars);
int				parser(char **str, va_list *vl, t_pars *pars);
int				proc_s(va_list *vl, t_pars *pars);
void			s_span(char *out, t_pars *pars);
int				proc_c(va_list *vl, t_pars *pars, char **str);
int				proc_u(va_list *vl, t_pars *pars);
void			u_accur(char *out, t_pars *pars);
void			u_span(char *out, t_pars *pars);
void			u_span_0(char *out, t_pars *pars);
int				proc_d(va_list *vl, t_pars *pars);
void			d_accur(char *out, t_pars *pars, int flag);
void			d_span(char *out, t_pars *pars, int flag);
void			d_span_0(char *out, t_pars *pars, int flag);
int				proc_x(va_list *vl, t_pars *pars, char x);
void			do_upper(char *out);
int				proc_p(va_list *vl, t_pars *pars);
void			p_span(char *out, t_pars *pars);
int				out_print(char *out);
char			*ft_u_itoa(unsigned int n);
size_t			ft_numbers_count(unsigned long long int n);

#endif
