/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 04:13:47 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/04 04:15:05 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strchar(char *s1, char c)
{
	char	*res;
	int		i;

	i = 0;
	if (!(s1))
	{
		if (!(res = ft_memalloc(sizeof(char) * 2)))
			return (NULL);
		res[i] = c;
	}
	else if (!(c))
		return (s1);
	else
	{
		i = ft_strlen(s1);
		if (!(res = ft_memalloc(sizeof(char) * i + 2)))
			return (NULL);
		ft_strcpy(res, s1);
		res[i] = c;
		res[i + 1] = '\0';
	}
	return (res);
}
