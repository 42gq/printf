/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_binchar_to_mbytes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 08:10:20 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 03:47:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_binchar_to_mbytes(char *str)
{
	int		i;
	int		j;
	int		a;
	int		res;
	char	*ret;

	j = 0;
	i = ft_strlen(str);
	a = (i / 8);
	ret = ft_memalloc(sizeof(char) * a + 1);
	while (i > 6)
	{
		res = 0;
		i -= 8;
		j = 7;
		while (j >= 0)
		{
			if (str[i + j] == '1')
				res += ft_pow(2, 7 - j);
			j--;
		}
		ret[--a] = (char)res;
	}
	ft_strdel(&str);
	return (ret);
}
