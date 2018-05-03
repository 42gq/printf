/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 05:26:39 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/09 07:16:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_arg(t_env *e)
{
	e->size_w = 0;
	e->nbrs = 0;
	e->nbr = 0;
	e->error = 0;
	e->condi = '\0';
	e->space = 0;
	e->diese = 0;
	e->plus = 0;
	e->minus = 0;
	e->null = 0;
	e->h = 0;
	e->j = 0;
	e->z = 0;
	e->l = 0;
	e->size_str = 0;
	e->preci_size = 0;
	e->field_size = 0;
	e->size_arg = 0;
	e->field = 0;
	e->preci = 0;
	e->size_num = 0;
	e->tmp = NULL;
	e->signs = 0;
}
