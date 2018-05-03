/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 05:21:12 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/09 07:55:42 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_error(int i)
{
	if (i == 1)
		ft_putstr("- format has not been allocated -Retry\n");
	if (i == 2)
		ft_putstr("- stockage format string failed -Retry\n");
	if (i == 3)
		ft_putstr("");
	if (i == 4)
		ft_putstr("- Bad options choice -\nPLease check your arguments\n");
	if (i == 5)
		ft_putstr("- Wrong options - Please check your arguments5555\n");
	if (i == 6)
		ft_putstr("- Options != somme_options, check ft_condition\n");
	if (i == 7)
		ft_putstr("");
}

int		ft_error_printf(int i)
{
	return (-1);
}
