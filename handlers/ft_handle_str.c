/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 05:53:58 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 05:54:33 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_str(char *v_arg, t_env *e)
{
	char	*add;
	char	*mem;

	mem = NULL;
	e->size_str = ft_strlen(v_arg);
	add = NULL;
	if (v_arg == NULL)
		add = ft_strdup("(null)");
	else if (!(add = ft_strdup(v_arg)))
		return (-1);
	mem = ft_apply_optionsstr(add, e);
	e->size += ft_strlen(mem);
	if (!(e->stock = ft_strjoinfree(e->stock, mem)))
		return (-1);
	return (1);
}
