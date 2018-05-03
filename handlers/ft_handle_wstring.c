/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 06:00:26 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:08:50 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_loop_wstring(wchar_t *arg, t_env *e, char *add, char *mem)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		add = ft_conv_wint_to_str((wint_t)arg[i], e);
		if (e->preci_size && e->size_w > e->preci)
		{
			ft_strclr(add);
			break ;
		}
		mem = ft_strjoin(mem, add);
		ft_strclr(add);
	}
	return (mem);
}

int		ft_handle_wstring(wchar_t *arg, t_env *e)
{
	char	*add;
	char	*mem;

	mem = NULL;
	add = NULL;
	if (arg == NULL)
		mem = ft_strdup("(null)");
	else
		mem = ft_loop_wstring(arg, e, add, mem);
	mem = ft_apply_optionsstr(mem, e);
	e->size += ft_strlen(mem);
	if (!(e->stock = ft_strjoinfree(e->stock, mem)))
		return (-1);
	return (1);
}
