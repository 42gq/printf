/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 07:23:59 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 09:30:47 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_field(char *str, int i, t_env *e)
{
	int	k;

	k = 0;
	if ((str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#'
		|| str[i] == '%') && e->field_size == 0)
	{
		if (e->field == 0)
		{
			e->field_size = -i;
			e->field = ft_atoi(&str[i + 1]);
		}
		if (e->field_size > 0 && e->field == 0)
		{
			e->field_size = 0;
			return (0);
		}
		return (-i);
	}
	return (0);
}

int		ft_check_preci(char *str, t_env *e)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		i--;
	if (!(k = ft_options_field(str, i, e)))
	{
		if ((str[i] == '.') && e->preci == 0)
		{
			e->preci_size = -(i - 1);
			e->preci = ft_atoi(&str[i + 1]);
			k = e->preci_size;
		}
		else
			return (0);
	}
	return (k);
}

int		ft_precision(char *str, t_env *e)
{
	int	i;
	int	k;

	i = (e->condi == '%') ? -1 : 0;
	while (str[i] != '%')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (e->condi == '%') ||
				(e->preci == 0 && str[i] == '.' && !ft_isdigit(str[i + 1])))
		{
			k = 0;
			if ((k = ft_check_preci(&str[i], e)) < 0)
				return (-1);
			if (k > 0)
				i -= (k - 1);
		}
		i--;
	}
	e->null = ft_zero(&str[i], e);
	e->size_arg = -i + 1;
	return (-i);
}
