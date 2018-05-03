/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 04:10:45 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/11 01:13:37 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hand_add(t_env *e, char *add)
{
	if (ft_strlen(add))
	{
		add = ft_strcpy_until(add, ft_strlen(add) - 1);
		if (!(e->stock = ft_strjoinfree(e->stock, add)))
			return (-1);
	}
	ft_cheat(e, 0, e->size);
	return (1);
}

int	ft_handle_char(char v_arg, t_env *e)
{
	char *add;
	char c;

	c = v_arg;
	add = NULL;
	if (!(add = ft_strchar(add, v_arg)) || c == 0)
		add = ft_strdup("A");
	add = ft_apply_optionschar(add, e);
	if (e->condi != 'C')
		e->size += ft_strlen(add);
	if (c == 0)
		return (ft_hand_add(e, add));
	if (!(e->stock = ft_strjoinfree(e->stock, add)))
		return (-1);
	return (1);
}
