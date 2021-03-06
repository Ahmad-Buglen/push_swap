# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 14:53:27 by dphyliss          #+#    #+#              #
#    Updated: 2020/07/01 14:53:27 by dphyliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC_DIR = source/

CHECKER = checker

SRC_CH = source/checker.c

OBJ_CH = $(SRC_CH:.c=.o)

PUSH_SWAP = push_swap

SRC_PS = $(addprefix $(SRC_DIR),\
		push_swap.c\
		optimization.c\
		set_index.c\
		sort_insert.c)

OBJ_PS = $(SRC_PS:.c=.o)

SRC_BASE = $(addprefix $(SRC_DIR),\
		swap.c\
		reverse.c\
		reverse_rotate.c\
		input_read.c)

OBJ_BASE = $(SRC_BASE:.c=.o)

LIB = libft/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = include/push_swap.h

all: $(LIB) $(PUSH_SWAP) $(CHECKER)

$(LIB):
	make -C libft/

$(PUSH_SWAP): $(OBJ_PS) $(OBJ_BASE) $(LIB)
	$(CC) $^ $(LIB) -o $@

$(OBJ_PS): $(HEADER)

$(OBJ_BASE): $(HEADER)

$(CHECKER): $(OBJ_CH) $(OBJ_BASE) $(LIB)
	$(CC) $^ $(LIB) -o $@

$(OBJ_CH): $(HEADER)

clean:
	make clean -C libft
	rm -rf source/*.o

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(LIB)

re: fclean all
