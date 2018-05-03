/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 01:00:56 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/09 07:11:25 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*force_strcpy_until(char *src, int i, char *dst)
{
	int		k;
	char	*tmp;

	ft_clean(dst);
	tmp = NULL;
	k = -1;
	if (!(tmp = ft_memalloc(sizeof(char) * i + 1)))
		return (NULL);
	while (++k < i)
		tmp[k] = src[k];
	return (tmp);
}

int		*cpy_tab_int(int *src, int *dst, int i)
{
	int	j;
	int	*tmp;

	free(dst);
	if (!(tmp = malloc(sizeof(int) * i)))
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = src[j];
		j++;
	}
	return (tmp);
}

void	apply_cheat(t_env *e, int i, int k)
{
	char	*tmp;

	tmp = NULL;
	if (e->cheat_size)
	{
		if (!(tmp = ft_memalloc(sizeof(char) * e->size + e->cheat_size)))
			return ;
	}
	while (++i < e->cheat_size)
	{
		while (k + i < e->cheat[i])
		{
			tmp[k + i] = e->stock[k];
			k++;
		}
		tmp[k + i] = '\0';
	}
	while (e->stock[k] != '\0')
	{
		tmp[k + i] = e->stock[k];
		k++;
	}
	tmp[k + i] = '\0';
	e->stock = force_strcpy_until(tmp, e->size, e->stock);
	ft_clean(tmp);
}

void	add_cheat(t_env *e, int p)
{
	int	i;
	int	*tmp;

	i = -1;
	tmp = NULL;
	e->cheat_size++;
	if (!(tmp = malloc(sizeof(int) * e->cheat_size)))
		e->error = 1;
	while (++i < e->cheat_size - 1)
		tmp[i] = e->cheat[i];
	tmp[i] = p - 1;
	while (--i >= 0)
		e->cheat[i] = 0;
	free(e->cheat);
	if (!(e->cheat = malloc(sizeof(int) * e->cheat_size)))
		return ;
	e->cheat = cpy_tab_int(tmp, e->cheat, e->cheat_size);
	while (++i < e->cheat_size)
		tmp[i] = 0;
	free(tmp);
}

void	ft_cheat(t_env *e, int k, int p)
{
	if (k == 0)
		add_cheat(e, p);
	else if (k == 1)
		apply_cheat(e, -1, 0);
}
