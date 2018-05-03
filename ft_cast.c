/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 00:47:34 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 04:07:31 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast2(t_env *e, va_list arg, int uns)
{
	e->nbrs = va_arg(arg, long long int);
	if (e->l == 2)
		ft_handle_longlongint(e);
	else if (e->j == 1)
		ft_handle_longlongint(e);
	else if (e->l == 1 || e->condi == 'D')
		ft_handle_longint(e);
	else if (e->z == 1)
	{
		e->nbrs = (size_t)e->nbrs;
		ft_handle_longint(e);
	}
	else if (e->h == 1)
		ft_handle_shortint(e);
	else if (e->h == 2)
		ft_handle_ssint(e);
	else
		ft_handle_int(e);
}

void	ft_cast(t_env *e, va_list arg, int uns)
{
	if (uns == 1)
	{
		e->nbr = va_arg(arg, uintmax_t);
		if (e->l == 2 || e->condi == 'p')
			ft_handle_llunt(e);
		else if (e->j == 1)
			ft_handle_llunt(e);
		else if (e->l == 1 || e->condi == 'U' || e->condi == 'O')
			ft_handle_lunt(e);
		else if (e->z == 1)
		{
			e->nbr = (size_t)e->nbr;
			ft_handle_lunt(e);
		}
		else if (e->h == 1)
			ft_handle_sunt(e);
		else if (e->h == 2)
			ft_handle_ssunt(e);
		else
			ft_handle_unt(e);
	}
	else
		ft_cast2(e, arg, uns);
}
