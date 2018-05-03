/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:53:33 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/06 07:32:23 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkway(char *str, t_env *e)
{
	int i;
	int	k;

	k = 0;
	i = 1;
	if (str[i] != '\0' && str[i] == '%')
		e->condi = '%';
	while (str[i] != '\0' && !(ft_condition(&str[i], e, 0)))
		i++;
	if (str[i] == '\0')
		return (-3);
	if ((k = ft_condition(&str[i], e, 1) < 0))
		return (-7);
	return (1);
}
