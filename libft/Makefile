# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:57:42 by cchauvie          #+#    #+#              #
#    Updated: 2015/04/09 13:41:52 by cchauvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean
.SUFFIXES:

############################################
## Definition des variables generales
############################################

OPATH = objs
SPATH = srcs
HPATH = includes

CFILE = total.mak
PFILE = progress.mak

############################################
## Definition des flags de compilation
############################################

CC = gcc
CCFLAGS = -I $(HPATH)/ -Wall -Wextra -Werror
CCFLAGS += -nostdlib -ansi
ifeq ($(CC_CONFIG), debug)
	CCFLAGS += -Wno-conversion -Wshadow -fno-builtin -nostdlib -fno-stack-protector -g
	COMMENT2 = > /dev/null
else
	COMMENT = @
endif

############################################
## Declaration des fichiers et nom du programme
############################################

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_itoa.c\
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_strcat.c ft_strcatf.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strtchr.c\
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_printf.c\
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_error.c \
	ft_tolower.c ft_toupper.c ft_strsdup.c ft_strndup.c ft_lists.c ft_lists2.c \
	ft_baseconv.c ft_put_tab.c ft_tabsize.c ft_isspace.c ft_realloc.c \
	ft_tab_split_from_id.c ft_tab_split_to_id.c ft_numlen.c ft_memdup.c \
	ft_dprintf.c ft_free_array.c  ft_free_str.c get_next_line.c

OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRCS))

############################################
## Regles de compilation
############################################

all: $(NAME)

$(NAME): $(OFILES) $(HPATH)
	@printf "\r\033[2K\033[33m[Building $(NAME)]\033[0m" $(COMMENT2)
	$(COMMENT)ar rc $(NAME) $(OFILES)
	$(COMMENT)ranlib $(NAME)
	@printf " -> \033[32m[Done]\033[0m\n" $(COMMENT2)

$(OPATH)/%.o: $(SPATH)/%.c
	@if ! test -f $(CFILE); then \
		COUNT=0; \
		for TMP in $(SRCS); do \
		COUNT=$$(($$COUNT + 1)); \
		done; \
		echo $$COUNT > $(CFILE); \
		fi
	@test -f $(PFILE) || (echo 0 > $(PFILE))
	@echo $$(($$(cat $(PFILE)) + 1)) > $(PFILE)
	@printf "\r\033[33m[$(NAME) : Compiling $(^)]\033[0m %3s%%" $$(($$(cat $(PFILE)) * 100 / $$(cat $(CFILE)))) $(COMMENT2)
	@mkdir -p $(@D)
	$(COMMENT)$(CC) $(CCFLAGS) -c $(^) -o $(@)

clean: clear_tmp
	@rm -rf $(OPATH)

fclean: clean
	@rm -f $(NAME)

clear_tmp:
	@rm -f $(CFILE) $(PFILE)

re: fclean all

############################################
## End
############################################
