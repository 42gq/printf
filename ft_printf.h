/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 00:44:17 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/11 02:34:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./SRC/libft/SRC/libft.h"
# include <stddef.h>
# include <locale.h>
# include <stdarg.h>

typedef struct		s_env
{
	long long int	nbrs;
	uintmax_t		nbr;
	char			*stock;
	int				error;
	char			condi;
	int				space;
	int				diese;
	int				plus;
	int				minus;
	int				null;
	int				h;
	int				j;
	int				z;
	int				l;
	int				size_str;
	int				preci_size;
	int				field_size;
	int				size_arg;
	int				field;
	int				preci;
	int				size_num;
	int				signs;
	char			*tmp;
	int				size;
	int				size_w;
	int				*cheat;
	int				cheat_size;
	int				add_size;
}					t_env;

int					ft_sprintf(char **cpy, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_cheat(t_env *e, int k, int p);
int					ft_zero(char *str, t_env *e);
char				*ft_strchar(char *s1, char c);
char				*ft_apply_optionschar(char *str, t_env *e);
int					ft_printf(const char *format, ...);
void				ft_init_arg(t_env *e);
int					ft_read(const char *format, va_list arg, t_env *e);
int					ft_stock(char *format, t_env *e);
int					ft_error_printf(int i);
int					ft_checkway(char *str, t_env *e);
int					ft_condition(char *str, t_env *e, int check);
int					ft_somme_option(t_env *e);
int					ft_precision(char *str, t_env *e);
void				ft_signs(char *str, t_env *e);
int					ft_save_arg(t_env *e, va_list arg);
int					ft_percent(t_env *e);
int					ft_handle_char(char v_arg, t_env *e);
int					ft_handle_int(t_env *e);
int					ft_handle_ssint(t_env *e);
int					ft_handle_shortint(t_env *e);
int					ft_handle_str(char *v_arg, t_env *e);
int					ft_handle_wchar(wint_t v_arg, t_env *e);
int					ft_handle_wstring(wchar_t *arg, t_env *e);
int					ft_handle_longint(t_env *e);
int					ft_handle_longlongint(t_env *e);
int					ft_handle_ssunt(t_env *e);
int					ft_handle_sunt(t_env *e);
int					ft_handle_str(char *v_arg, t_env *e);
int					ft_handle_wchar(wint_t v_arg, t_env *e);
int					ft_handle_wstring(wchar_t *v_arg, t_env *e);
int					ft_handle_llunt(t_env *e);
int					ft_handle_lunt(t_env *e);
int					ft_handle_unt(t_env *e);
char				*ft_apply_options(char *str, t_env *e);
char				*ft_signs_pass(char *str, t_env *e);
char				*ft_apply_preci(char *str, t_env *e);
char				*ft_minus(char *str, t_env *e);
char				*ft_conv_wint_to_str(wint_t c, t_env *e);
char				*ft_apply_minus(char *str, int j);
char				*ft_convert_binchar_to_mbytes(char *str);
void				ft_cast(t_env *e, va_list arg, int uns);
char				*ft_apply_optionsstr(char *str, t_env *e);
char				*ft_diese(char *str, t_env *e);
#endif
