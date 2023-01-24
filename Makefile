# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 13:27:39 by jduval            #+#    #+#              #
#    Updated: 2023/01/24 12:15:19 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifdef BONUS
NAME 		=	fdf_bonus
else
NAME 		=	fdf
endif

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft mlx Xext X11 m z

LIBS_TARGET =	libft/libft.a		\
				mlx/libmlx_Linux.a	\

INCLUDES	=	libft/include 	\
				mlx				\
				/usr/lib		\

###############################################################################

BUILD_DIR 	= 	.build

SRCS 		=	fdf_draw.c				fdf_rotate_x.c		\
				fdf_rotate_y.c			fdf_rotate_z.c		\
				fdf_parsing.c			fdf_middle.c		\
				fdf_parsing_utils.c		fdf_utils.c 		\
				fdf_shifting.c 			fdf_link_points.c 	\
				fdf_isometric.c			fdf_user_exit.c		\

SRCS_BONUS	=	fdf_clear_bonus.c		fdf_key_bonus.c		\
				fdf_zoom_bonus.c	\
				fdf_reset_bonus.c 		fdf_rotation_bonus.c\
				fdf_translate.c

ifdef BONUS
SRCS += $(SRCS_BONUS) fdf_bonus.c
else
SRCS += fdf.c
endif

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS = $(OBJS:.o=.d)


###############################################################################

CC 			=	clang

CFLAGS 		= -Werror -Wextra -Wall -ggdb3 -O3

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

bonus: 
	$(MAKE) BONUS=1 all
.PHONY:bonus

###############################################################################

clean:
	@${MAKE} -C libft/ clean
	rm -rf .build
.PHONY:clean

fclean: clean 
	@${MAKE} -C libft/ fclean
	rm -f $(NAME) fdf_bonus
.PHONY: fclean

re: fclean all
.PHONY: re
