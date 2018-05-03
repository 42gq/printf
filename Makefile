# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gquerre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 05:42:43 by gquerre           #+#    #+#              #
#    Updated: 2017/10/11 01:12:47 by gquerre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  = ./apply/ft_place_min.c\
./apply/ft_apply_minus.c\
./apply/ft_apply_options.c\
./apply/ft_apply_preci.c\
./apply/ft_diese.c\
./apply/ft_preci_char.c\
./apply/ft_strchar.c\
./apply/ft_signs_pass.c\
./apply/ft_preci_str.c\
./handlers/ft_handle_str.c\
./handlers/ft_handle_char.c\
./handlers/ft_handle_int.c\
./handlers/ft_handle_longint.c\
./handlers/ft_handle_llint.c\
./handlers/ft_handle_unsigned_int.c\
./handlers/ft_handle_lunt.c\
./handlers/ft_handle_llunt.c\
./handlers/ft_handle_sunt.c\
./handlers/ft_handle_ssunt.c\
./handlers/ft_handle_ssint.c\
./handlers/ft_handle_short.c\
./handlers/ft_handle_wstring.c\
./handlers/ft_handle_wchar.c\
./ft_printf.c\
./ft_dprintf.c\
./ft_sprintf.c\
./ft_cast.c\
./ft_checkway.c\
./ft_convert_binchar_to_mbytes.c\
./ft_error_printf.c\
./ft_init_arg.c\
./ft_percent.c\
./ft_cheat.c\
./ft_condition.c\
./ft_conv_mbytes_str.c\
./ft_signs.c\
./ft_somme_option.c\
./ft_save_arg.c\
./ft_read.c\
./ft_stock.c\
./ft_precision.c\
./ft_zero.c\
./SRC/libft/SRC/ft_insert.c\
./SRC/libft/SRC/ft_lutoa.c\
./SRC/libft/SRC/ft_llutoa.c\
./SRC/libft/SRC/ft_sutoa.c\
./SRC/libft/SRC/ft_ssutoa.c\
./SRC/libft/SRC/ft_litoa.c\
./SRC/libft/SRC/ft_llitoa.c\
./SRC/libft/SRC/ft_sitoa.c\
./SRC/libft/SRC/ft_ssitoa.c\
./SRC/libft/SRC/ft_capitalize.c\
./SRC/libft/SRC/ft_replace_char.c\
./SRC/libft/SRC/ft_add_1stcharbool.c\
./SRC/libft/SRC/ft_add_1stchar.c\
./SRC/libft/SRC/ft_pow.c\
./SRC/libft/SRC/ft_utoabase.c\
./SRC/libft/SRC/ft_itoabase.c\
./SRC/libft/SRC/ft_strdup_until.c\
./SRC/libft/SRC/ft_strcpy_until.c\
./SRC/libft/SRC/get_next_line.c\
./SRC/libft/SRC/ft_strclr_until.c\
./SRC/libft/SRC/ft_strjoinfree.c\
./SRC/libft/SRC/ft_strchr_count.c\
./SRC/libft/SRC/ft_memset.c\
./SRC/libft/SRC/ft_bzero.c\
./SRC/libft/SRC/ft_memcpy.c\
./SRC/libft/SRC/ft_memccpy.c\
./SRC/libft/SRC/ft_memmove.c\
./SRC/libft/SRC/ft_memchr.c\
./SRC/libft/SRC/ft_memcmp.c\
./SRC/libft/SRC/ft_strlen.c\
./SRC/libft/SRC/ft_strdup.c\
./SRC/libft/SRC/ft_strcpy.c\
./SRC/libft/SRC/ft_strncpy.c\
./SRC/libft/SRC/ft_strcat.c\
./SRC/libft/SRC/ft_strncat.c\
./SRC/libft/SRC/ft_strlcat.c\
./SRC/libft/SRC/ft_strchr.c\
./SRC/libft/SRC/ft_strrchr.c\
./SRC/libft/SRC/ft_strstr.c\
./SRC/libft/SRC/ft_strnstr.c\
./SRC/libft/SRC/ft_strncmp.c\
./SRC/libft/SRC/ft_atoi.c\
./SRC/libft/SRC/ft_isalpha.c\
./SRC/libft/SRC/ft_isdigit.c\
./SRC/libft/SRC/ft_isalnum.c\
./SRC/libft/SRC/ft_isascii.c\
./SRC/libft/SRC/ft_isprint.c\
./SRC/libft/SRC/ft_toupper.c\
./SRC/libft/SRC/ft_tolower.c\
./SRC/libft/SRC/ft_memalloc.c\
./SRC/libft/SRC/ft_memdel.c\
./SRC/libft/SRC/ft_strnew.c\
./SRC/libft/SRC/ft_strcmp.c\
./SRC/libft/SRC/ft_strdel.c\
./SRC/libft/SRC/ft_strclr.c\
./SRC/libft/SRC/ft_striter.c\
./SRC/libft/SRC/ft_striteri.c\
./SRC/libft/SRC/ft_strmap.c\
./SRC/libft/SRC/ft_strmapi.c\
./SRC/libft/SRC/ft_strequ.c\
./SRC/libft/SRC/ft_strnequ.c\
./SRC/libft/SRC/ft_strsub.c\
./SRC/libft/SRC/ft_strjoin.c\
./SRC/libft/SRC/ft_strtrim.c\
./SRC/libft/SRC/ft_strsplit.c\
./SRC/libft/SRC/ft_itoa.c\
./SRC/libft/SRC/ft_putchar.c\
./SRC/libft/SRC/ft_putstr.c\
./SRC/libft/SRC/ft_putendl.c\
./SRC/libft/SRC/ft_putnbr.c\
./SRC/libft/SRC/ft_putchar_fd.c\
./SRC/libft/SRC/ft_putstr_fd.c\
./SRC/libft/SRC/ft_putendl_fd.c\
./SRC/libft/SRC/ft_putnbr_fd.c\
./SRC/libft/SRC/ft_lstnew.c\
./SRC/libft/SRC/ft_lstadd.c\
./SRC/libft/SRC/ft_lstdelone.c\
./SRC/libft/SRC/ft_lstiter.c\
./SRC/libft/SRC/ft_lstmap.c\
./SRC/libft/SRC/ft_lstdel.c\
./SRC/libft/SRC/ft_countiter.c\
./SRC/libft/SRC/ft_countstriter.c\
./SRC/libft/SRC/ft_dcmpt.c\
./SRC/libft/SRC/ft_checkedge.c\
./SRC/libft/SRC/ft_checkrectangle.c\
./SRC/libft/SRC/ft_clean.c

FLAG = -Wextra -Wall -Werror

SUPP = ./ft_printf.h ./SRC/libft/SRC/libft.h

OBJ  = ./ft_place_min.o\
./ft_apply_minus.o\
./ft_apply_options.o\
./ft_apply_preci.o\
./ft_diese.o\
./ft_preci_char.o\
./ft_strchar.o\
./ft_signs_pass.o\
./ft_preci_str.o\
./ft_handle_str.o\
./ft_handle_char.o\
./ft_handle_int.o\
./ft_handle_longint.o\
./ft_handle_llint.o\
./ft_handle_unsigned_int.o\
./ft_handle_lunt.o\
./ft_handle_llunt.o\
./ft_handle_sunt.o\
./ft_handle_ssunt.o\
./ft_handle_ssint.o\
./ft_handle_short.o\
./ft_handle_wstring.o\
./ft_handle_wchar.o\
./ft_printf.o\
./ft_dprintf.o\
./ft_sprintf.o\
./ft_cast.o\
./ft_checkway.o\
./ft_convert_binchar_to_mbytes.o\
./ft_error_printf.o\
./ft_init_arg.o\
./ft_percent.o\
./ft_cheat.o\
./ft_condition.o\
./ft_conv_mbytes_str.o\
./ft_signs.o\
./ft_somme_option.o\
./ft_save_arg.o\
./ft_read.o\
./ft_stock.o\
./ft_precision.o\
./ft_zero.o\
./ft_insert.o\
./ft_lutoa.o\
./ft_llutoa.o\
./ft_sutoa.o\
./ft_ssutoa.o\
./ft_litoa.o\
./ft_llitoa.o\
./ft_sitoa.o\
./ft_ssitoa.o\
./ft_capitalize.o\
./ft_replace_char.o\
./ft_add_1stcharbool.o\
./ft_add_1stchar.o\
./ft_pow.o\
./ft_utoabase.o\
./ft_itoabase.o\
./ft_strdup_until.o\
./ft_strcpy_until.o\
./get_next_line.o\
./ft_strclr_until.o\
./ft_strjoinfree.o\
./ft_strchr_count.o\
./ft_memset.o\
./ft_bzero.o\
./ft_memcpy.o\
./ft_memccpy.o\
./ft_memmove.o\
./ft_memchr.o\
./ft_memcmp.o\
./ft_strlen.o\
./ft_strdup.o\
./ft_strcpy.o\
./ft_strncpy.o\
./ft_strcat.o\
./ft_strncat.o\
./ft_strlcat.o\
./ft_strchr.o\
./ft_strrchr.o\
./ft_strstr.o\
./ft_strnstr.o\
./ft_strncmp.o\
./ft_atoi.o\
./ft_isalpha.o\
./ft_isdigit.o\
./ft_isalnum.o\
./ft_isascii.o\
./ft_isprint.o\
./ft_toupper.o\
./ft_tolower.o\
./ft_memalloc.o\
./ft_memdel.o\
./ft_strnew.o\
./ft_strcmp.o\
./ft_strdel.o\
./ft_strclr.o\
./ft_striter.o\
./ft_striteri.o\
./ft_strmap.o\
./ft_strmapi.o\
./ft_strequ.o\
./ft_strnequ.o\
./ft_strsub.o\
./ft_strjoin.o\
./ft_strtrim.o\
./ft_strsplit.o\
./ft_itoa.o\
./ft_putchar.o\
./ft_putstr.o\
./ft_putendl.o\
./ft_putnbr.o\
./ft_putchar_fd.o\
./ft_putstr_fd.o\
./ft_putendl_fd.o\
./ft_putnbr_fd.o\
./ft_lstnew.o\
./ft_lstadd.o\
./ft_lstdelone.o\
./ft_lstiter.o\
./ft_lstmap.o\
./ft_lstdel.o\
./ft_countiter.o\
./ft_countstriter.o\
./ft_dcmpt.o\
./ft_checkedge.o\
./ft_checkrectangle.o\
./ft_clean.o

all: $(NAME)

$(NAME): $(SRC)
	gcc -I $(SUPP) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.Phony: clean all fclean re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
