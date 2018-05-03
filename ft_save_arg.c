/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 08:05:15 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 05:27:52 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_arg2(t_env *e, va_list arg)
{
	if (e->condi == 'C' || (e->condi == 'c' && e->l == 1))
		ft_handle_wchar(va_arg(arg, wint_t), e);
	else if (e->condi == 'c')
		ft_handle_char((char)va_arg(arg, int), e);
}

int		ft_save_arg(t_env *e, va_list arg)
{
	if (e->condi == 'x' || e->condi == 'X' || e->condi == 'u' || e->condi == 'O'
			|| e->condi == 'b' || e->condi == 'U'
			|| e->condi == 'o' || e->condi == 'p')
		ft_cast(e, arg, 1);
	else if (e->condi == 'i' || e->condi == 'd' || e->condi == 'D')
		ft_cast(e, arg, 0);
	else if (e->condi == 'S' || (e->condi == 's' && e->l == 1))
		ft_handle_wstring(va_arg(arg, wchar_t*), e);
	else if (e->condi == 's')
		ft_handle_str(va_arg(arg, char*), e);
	else if (e->condi == '%')
		return (ft_percent(e));
	ft_save_arg2(e, arg);
	return (e->size_arg);
}
