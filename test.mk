# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 08:11:27 by jduval            #+#    #+#              #
#    Updated: 2023/01/06 08:40:06 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS		:=	$(shell find tests -name '*.c')
TESTS_OBJS	:=	$(TESTS:%.c=$(BUILD_DIR)/%.o)

ARCHIVE		:=	tests/fdf.a
RUNNER		:=	tests/test

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

$(TEST_OBJS): CPPFLAGS+= -I tests/

$(TEST_OBJS): CFLAGS = -Wall -Wextra -ggdb3

$(RUNNER): $(LIBS_TARGET) $(ARCHIVE) $(TESTS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTS_OBJS) $(ARCHIVE) $(LDLIBS) -o $(RUNNER)

test: fclean $(RUNNER)
	valgrind -q --leak-check=full --show-reachable=yes $(RUNNER)
.PHONY: test
