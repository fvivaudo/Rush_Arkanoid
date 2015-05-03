# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/31 16:58:29 by cchauvie          #+#    #+#              #
#    Updated: 2015/05/03 22:50:31 by cchauvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean
.SUFFIXES:

############################################
## Definition des variables generales
############################################

CPATH = srcs
OPATH = objs
HPATH = includes

LIBPATH = libft
LIB_NAME = $(LIBPATH)/libft.a

GLFWPATH = glfw
GLFW_NAME = $(GLFWPATH)/src/libglfw3.a

############################################
## Definition des flags de compilation
############################################

LD = gcc
LDFLAGS = -lc -L $(LIBPATH) -L $(GLFWPATH) -framework AGL -framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo -framework GLUT

CC = $(LD)
CCFLAGS = -I $(HPATH)/ -I $(LIBPATH)/$(HPATH) -I $(GLFWPATH)/include
CCFLAGS += -Wall -Wextra -Werror -Wno-deprecated

ifeq ($(CC_CONFIG), debug)
	CCFLAGS += -Wno-conversion -Wshadow -fno-builtin -nostdlib -fno-stack-protector -g
	COMMENT2 = > /dev/null
else
	COMMENT = @
endif

############################################
## Declaration des fichiers et nom du programme
############################################

NAME1 = arkanoid
SRCS1 = main.c loadmap.c window.c game.c math.c draw.c
SRCSDIR1 = $(CPATH)
HFILES1 = $(HPATH)
OBJSDIR1 = $(patsubst $(CPATH)%, $(OPATH)%, $(SRCSDIR1))
OBJSFILES1 = $(patsubst %.c, $(OBJSDIR1)/%.o, $(SRCS1))

NAMES = $(NAME1)

############################################
## Regles de compilation
############################################

all: LIB_NAME GLFW_NAME $(NAMES)

LIB_NAME: $(LIBPATH)/$(HPATH)
	@make -C $(LIBPATH)

GLFW_NAME:
	@git submodule init
	@git submodule update
	@if [ ! -f $(GLFW_NAME) ]; then \
		pushd $(GLFWPATH) ; \
		cmake . ; \
		popd ; \
		make -C $(GLFWPATH) ; \
	fi

###########
# Can Duplycate and increase for multi-programs
# #########

$(NAME1): $(OBJSFILES1) $(LIB_NAME) $(GLFW_NAME)
	@printf "\033[33m[Building $(NAME1)]\033[0m" $(COMMENT2)
	$(COMMENT)$(LD) $(^) -o $(@) $(LDFLAGS)
	@printf " -> \033[32m[Done]\033[0m\n" $(COMMENT2)

$(OBJSDIR1)/%.o: $(SRCSDIR1)/%.c $(LIBPATH)/$(HPATH) $(HFILES1)
	@mkdir -p $(@D)
	$(COMMENT)$(CC) $(CCFLAGS) -c -o $(@) $(<)

###########
# End
###########

clean:
	@make -C $(LIBPATH) clean
	@rm -rf $(OPATH)
	@echo "- Clean done."

fclean: clean
	@make -C $(LIBPATH) fclean
	@rm -f $(NAMES)
	@echo "- Fclean done."

re: fclean all

############################################
## End
############################################
