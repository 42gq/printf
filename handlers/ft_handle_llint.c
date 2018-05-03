/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_llint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 02:42:59 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 01:07:47 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_stocklonglongitoa(long long int a)
{
	char	*str;

	str = ft_llitoa(a);
	return (str);
}

int		ft_handle_longlongint(t_env *e)
{
	char	*add;

	e->nbrs = (long long int)e->nbrs;
	add = NULL;
	if (!(add = ft_stocklonglongitoa(e->nbrs)))
		return (-1);
	add = ft_apply_options(add, e);
	e->size += ft_strlen(add);
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
