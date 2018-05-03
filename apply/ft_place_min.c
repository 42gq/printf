/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 03:04:05 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 00:38:49 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_add_minus(char *str, t_env *e, int i, int j)
{
	char	*add;

	add = NULL;
	if (i != 0)
	{
		add = ft_strnew(j);
		str[i - 1] = '-';
		add = ft_strcpy(add, str);
	}
	else if (e->field == j && str[0] == '0' && e->field != e->preci)
	{
		add = ft_strdup(str);
		add[0] = '-';
	}
	else
		add = ft_add_1stchar(str, '-');
	while (j > 0 && add[j] != ' ' && add[j] != '-')
		j--;
	if (add[j] == ' ' && j >= 1 && (add[j - 1] == '0' || add[j - 1] == '-'))
		add[j] = '0';
	ft_strdel(&str);
	return (add);
}

char	*ft_minus(char *str, t_env *e)
{
	char	*add;
	int		i;
	int		j;
	int		check;

	add = NULL;
	i = 0;
	check = 0;
	j = ft_strlen(str);
	while (str[i] != '\0' && check == 0)
		check = (str[i++] == '-') ? 1 : 0;
	if (check == 1)
	{
		str[i - 1] = (e->field == e->preci + 1 && e->field == j) ? '0' : ' ';
		i = 0;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		add = ft_add_minus(str, e, i, j);
		return (add);
	}
	return (str);
}
