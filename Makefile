# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 13:27:39 by jduval            #+#    #+#              #
#    Updated: 2023/01/09 14:12:56 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fdf

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft mlx Xext X11 m z

LIBS_TARGET =	libft/libft.a 					\
				minilibx-linux/libmlx_Linux.a 	\

INCLUDES	=	libft/include	\
				minilibx-linux	\
				/usr/lib		\

###############################################################################

BUILD_DIR 	= 	.build

SRCS 		=	main.c \
				fdf_draw.c		fdf_revise_x.c	\
				fdf_revise_y.c	fdf_revise_z.c	\

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS = $(OBJS:.o=.d)


###############################################################################

CC 			=	clang

CFLAGS 		=	-Werror -Wextra -Wall -ggdb3

CPPFLAGS 	=	-MMD -MP $(addprefix -I,$(INCLUDES))

LDFLAGS		=	$(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS		=	$(addprefix -l,$(LIBS))

DIRDUP 		= 	mkdir -p $(@D) 


###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	@$(MAKE) -C $(dir $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS) test.mk

###############################################################################

clean:
	@${MAKE} -C libft/ clean
	rm -rf .build
.PHONY:clean

fclean: clean 
	@${MAKE} -C libft/ fclean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
