/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 07:44:08 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 05:27:11 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_doub(char *str, char c, t_env *e)
{
	int i;

	i = 0;
	if (e->h > 1 || e->h < 0 || e->l > 1 || e->l < 0)
	{
		if (e->h > 1)
			e->h = -1;
		if (e->l > 1)
			e->l = -1;
		return (-1);
	}
	if ((c == 'h' && e->h == 1) || (c == 'l' && e->l == 1))
	{
		if (str[i + 1] != c)
			return (-1);
		else
			return (2);
	}
	return (1);
}

void	ft_condition3(char str, t_env *e)
{
	if (str == 'j')
		e->j += 1;
	if (str == 'z')
		e->z += 1;
}

void	ft_condition2(char *str, t_env *e)
{
	int i;
	int	k;

	i = 0;
	if (ft_precision(&str[i], e) < 0)
		e->error = 1;
	while (str[i] != '%' && !(ft_isdigit(str[i])))
	{
		ft_condition3(str[i], e);
		if (str[i] == 'h')
			e->h = ft_doub(&str[i], str[i], e);
		if (str[i] == 'l')
			e->l = ft_doub(&str[i], str[i], e);
		i--;
	}
	k = (e->condi == '%' && str[i] == '%') ? -1 : 0;
	while (str[i + k] != '%')
		k--;
	ft_signs(&str[i + k + 1], e);
}

int		ft_condition(char *str, t_env *e, int check)
{
	int i;

	i = 0;
	e->size_arg = 0;
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'd' || str[i] == 'b'
			|| str[i] == 'p' || str[i] == 'O' || str[i] == 'o'
			|| str[i] == 'i' || str[i] == 'D' || str[i] == '%'
			|| str[i] == 'x' || str[i] == 'X' || str[i] == 'u'
			|| str[i] == 'U' || str[i] == 'c' || str[i] == 'C')
	{
		e->condi = str[i];
		if (check == 1)
		{
			ft_condition2(str, e);
			if (e->h < 0 || e->l < 0)
				return (-4);
			if (e->size_arg - ft_somme_option(e) != 0)
			{
				return (-6);
			}
		}
		return (1);
	}
	return (0);
}
