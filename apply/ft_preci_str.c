/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 05:06:04 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 07:16:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_keep_size(char *str, int i)
{
	char	*res;

	res = NULL;
	res = ft_memalloc(sizeof(char) * i + 1);
	res = ft_strncpy(res, str, i);
	free(str);
	return (res);
}

char	*ft_preci_str(char *str, t_env *e, int j)
{
	char	*add;
	int		i;
	int		k;

	add = NULL;
	j = 0;
	k = 0;
	i = ft_strlen(str);
	if (e->preci_size && i > e->preci)
	{
		str = ft_keep_size(str, e->preci);
		i = e->preci;
	}
	if (i < e->field)
	{
		add = ft_memalloc(sizeof(char) * (e->field + 1));
		while ((e->field - (i + k)) > 0)
			add[k++] = (e->null > 0 && e->minus == 0) ? '0' : ' ';
		while (j < i && k < e->field + 1)
			add[k++] = str[j++];
		add[k] = '\0';
		ft_strdel(&str);
		return (add);
	}
	return (str);
}

char	*ft_apply_optionsstr(char *str, t_env *e)
{
	char	*add;

	add = NULL;
	add = ft_preci_str(str, e, 0);
	if (e->minus)
		add = ft_apply_minus(add, 0);
	return (add);
}
