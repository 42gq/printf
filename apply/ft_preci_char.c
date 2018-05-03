/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 04:07:22 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 03:42:54 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_precichar(char *str, t_env *e)
{
	char	*add;
	int		i;

	i = 0;
	if (e->field > 1)
	{
		if (!(add = (str) ? ft_memalloc(e->field + 1) : ft_memalloc(e->field)))
			return (NULL);
		if (e->null > 0)
		{
			while (i < e->field - 1)
				add[i++] = '0';
		}
		else
			while (i < e->field - 1)
				add[i++] = ' ';
		add[e->field - 1] = (str) ? str[0] : '\0';
		if (str)
			add[e->field] = '\0';
		return (add);
	}
	return (str);
}

char	*ft_apply_optionschar(char *str, t_env *e)
{
	char	*add;

	add = NULL;
	add = ft_strdup(ft_precichar(str, e));
	if (e->minus)
		add = ft_apply_minus(add, 0);
	return (add);
}
