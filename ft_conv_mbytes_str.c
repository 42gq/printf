/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_mbytes_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 05:00:18 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/10 04:30:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mask(int i, t_env *e)
{
	int		k;
	char	*str;

	e->size_w += i;
	k = 0;
	str = NULL;
	if (!(str = ft_memalloc(sizeof(char) * (i * 8) + 1)))
		return (NULL);
	while (k < (i * 8))
		str[k++] = 'x';
	k = 0;
	while (i > 1 && k < i)
		str[k++] = '1';
	str[k--] = '0';
	while (k > 0)
	{
		str[((i - k) * 8)] = '1';
		str[((i - k) * 8 + 1)] = '0';
		k--;
	}
	str[i * 8] = '\0';
	return (str);
}

char	*put_bytes_into(t_env *e, char *str)
{
	int	i;
	int k;

	i = ft_strlen(e->tmp);
	k = ft_strlen(str);
	while (i > 0)
	{
		if (str[--k] == 'x')
		{
			i--;
			str[k] = e->tmp[i];
		}
	}
	while (k >= 0)
	{
		str[k] = (str[k] == 'x') ? '0' : str[k];
		k--;
	}
	ft_strdel(&e->tmp);
	return (str);
}

char	*ft_split_mbytes(t_env *e, int i)
{
	char	*str;

	str = NULL;
	if (i < 8)
		str = ft_mask(1, e);
	else if (i < 12)
		str = ft_mask(2, e);
	else if (i < 18)
		str = ft_mask(3, e);
	else if (i < 22)
		str = ft_mask(4, e);
	else
		return (NULL);
	str = put_bytes_into(e, str);
	return (str);
}

int		ft_convert_deci_to_binary(wint_t c, int n, t_env *e)
{
	int				i;
	int				k;
	static size_t	l;

	i = 1;
	k = 0;
	if (c == 0)
		return ((l) ? l : 0);
	while (i <= c)
	{
		i *= 2;
		k++;
	}
	if (n == 1)
	{
		e->tmp = ft_memalloc(sizeof(char) * k + 1);
		l = k;
		while (k > 0)
			e->tmp[--k] = '0';
		k = l;
	}
	e->tmp[l - k] = '1';
	c = c - (i / 2);
	return (ft_convert_deci_to_binary(c, 2, e));
}

char	*ft_conv_wint_to_str(wint_t c, t_env *e)
{
	int		i;
	char	*str;
	char	*res;

	str = NULL;
	res = NULL;
	if (c == '\0')
	{
		res = ft_strdup("\0");
		e->size_w += 1;
	}
	else if ((i = ft_convert_deci_to_binary(c, 1, e)))
	{
		str = ft_split_mbytes(e, i);
		res = ft_convert_binchar_to_mbytes(str);
	}
	return (res);
}
