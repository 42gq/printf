/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diese.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 04:04:49 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 04:30:13 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_checkzero(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0' && str[k] == '0')
		k++;
	if (k >= 2)
		return (2);
	return (0);
}

char	*ft_diese(char *str, t_env *e)
{
	int		i;
	char	*add;

	i = 0;
	add = NULL;
	if ((e->condi != 'p' && ((!str || (str[0] == '0' && ft_strlen(str) == 1))
			&& (e->field != ft_strlen(str)))) || !(str))
		return (str);
	while (str[i] == ' ')
		i++;
	if (i == 0 && e->preci != ft_strlen(str) &&
			e->condi != 'o' && e->condi != 'O')
		i = ft_checkzero(str);
	if ((e->condi == 'o' || e->condi == 'O'))
	{
		if (str[i] != '0')
			add = ft_insert(str, i, "0");
		return (add);
	}
	else if ((e->condi == 'x' || e->condi == 'X') &&
			(e->nbr == 0 || (e->preci_size && e->preci == 0)))
		return (str);
	else
		return (ft_insert(str, i, "0x"));
	return (str);
}
