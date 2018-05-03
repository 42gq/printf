/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 04:55:48 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 09:25:40 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_apply_options(char *str, t_env *e)
{
	if (((str[0] == '0' && str[1] == '\0') || (str[0] == '\0'))
			&& e->preci_size && e->preci == 0)
		str[0] = '\0';
	str = ft_apply_preci(str, e);
	if (e->condi == 'i' || e->condi == 'd')
	{
		str = ft_signs_pass(str, e);
		str = ft_minus(str, e);
	}
	if (str && (e->condi == 'p' || (e->diese == 1 && (e->condi == 'x'
			|| e->condi == 'X' || e->condi == 'o' || e->condi == 'O'))))
		str = ft_diese(str, e);
	if (e->minus == 1)
		str = ft_apply_minus(str, 0);
	return (str);
}
