/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 02:44:20 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 01:15:34 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_stockshortitoa(signed short int a)
{
	char	*str;

	str = NULL;
	str = ft_sitoa(a);
	return (str);
}

int		ft_handle_shortint(t_env *e)
{
	char	*add;

	add = NULL;
	e->nbrs = (signed short int)e->nbrs;
	if (!(add = ft_stockshortitoa(e->nbrs)))
		return (-1);
	add = ft_apply_options(add, e);
	e->size += ft_strlen(add);
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
