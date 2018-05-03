/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signs_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 03:45:11 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 04:11:59 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_signs_pass(char *str, t_env *e)
{
	char	*add;
	int		i;
	int		j;

	add = NULL;
	j = 0;
	i = ft_strlen(str);
	if ((e->plus || e->space) && !ft_strchr(str, '-'))
	{
		while (j <= i && str[j] == ' ')
			j++;
		if (j == 0 && (e->preci == i || (e->field < i)))
			add = ft_add_1stcharbool(str, e->plus, '+', ' ');
		else if (j == 0 && e->field == i &&
				(str[j] == ' ' || str[j] == '0'))
			add = ft_replace_char(str, j, (e->plus) ? '+' : ' ');
		else if (j > 0)
			add = ft_replace_char(str, j - 1, (e->plus) ? '+' : ' ');
		else
			return (str);
		ft_strdel(&str);
		return (add);
	}
	return (str);
}
