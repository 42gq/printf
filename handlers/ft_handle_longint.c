/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_longint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 07:02:26 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/02 06:35:51 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_stocklongitoa(long a)
{
	char	*str;

	str = ft_litoa(a);
	return (str);
}

int		ft_handle_longint(t_env *e)
{
	char	*add;

	add = NULL;
	if (!e->z)
		e->nbrs = (long int)e->nbrs;
	if (!(add = ft_stocklongitoa(e->nbrs)))
		return (-1);
	add = ft_apply_options(add, e);
	e->size += ft_strlen(add);
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
