/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 01:42:10 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 03:58:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sprintf(char **cpy, const char *format, ...)
{
	va_list arg;
	int		res;
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		return (-1);
	e->size = 0;
	e->cheat_size = 0;
	e->cheat = NULL;
	if (e->stock)
		ft_strclr(e->stock);
	e->stock = ft_strnew(1);
	ft_init_arg(e);
	va_start(arg, format);
	res = ft_read(format, arg, e);
	*cpy = ft_strdup(e->stock);
	ft_strdel(&e->stock);
	free(e);
	va_end(arg);
	return (res);
}
