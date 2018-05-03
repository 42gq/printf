/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_preci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 05:00:09 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 09:28:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_apply_preci(char *str, t_env *e)
{
	char	*add;
	int		i;
	int		u;
	int		j;

	u = (e->field > e->preci) ? e->field : e->preci;
	j = 0;
	i = ft_strlen(str);
	if (i < e->field || i < e->preci)
	{
		add = ft_memalloc(sizeof(char) * u + 1);
		while (e->preci + j < e->field && j < e->field - i)
		{
			if (e->preci_size == 0)
				add[j++] = (e->null && !e->minus) ? '0' : ' ';
			else
				add[j++] = (e->preci + 1 == e->field &&
					ft_strchr(str, '-')) ? '0' : ' ';
		}
		while ((u - j) > i)
			add[j++] = (str[0] != '\0' && e->preci != 1) ? '0' : ' ';
		add[j] = '\0';
		return (ft_strjoinfree(add, str));
	}
	return (str);
}
