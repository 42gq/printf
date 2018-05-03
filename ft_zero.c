/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:24:21 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/05 03:30:09 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zero(char *str, t_env *e)
{
	int	i;
	int	a;

	i = 1;
	while (str[i + e->null] != '\0' && !(ft_condition(&str[i + e->null], e, 0)))
	{
		if ((ft_isdigit(str[i + e->null]) || str[i + e->null] == '.')
				&& str[i + e->null] != '0')
		{
			while (ft_isdigit(str[i + e->null]) || str[i + e->null] == '.')
				i++;
		}
		else if (str[i + e->null] == '0')
		{
			a = 0;
			while (str[i + e->null + a] != '\0' && str[i + e->null + a] == '0')
				a++;
			if (ft_isdigit(str[i + e->null + a]) && e->field_size)
				e->field_size -= a;
			e->null += a;
		}
		else
			i++;
	}
	return (e->null);
}
