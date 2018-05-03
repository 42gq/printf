/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_somme_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 06:32:46 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 09:30:23 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_somme_option(t_env *e)
{
	int i;

	i = e->space + e->h + e->diese + e->null + e->minus
		+ e->preci_size + e->field_size + e->plus + e->l + e->j + e->z + 2;
	return (i);
}
