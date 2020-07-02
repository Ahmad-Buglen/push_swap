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

# SRC_BASE = swap.c reverse.c reverse_rotete.c read_input.c
# SRC_PUSH_SWAP =	push_swap.c	optimization.c set_index.c sort_insert.c
# OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
# OBJ_BASE = $(SRC_BASE:.c=.o)

SRC_DIR = source/

SRC_CHECKER = $(SRC_DIR)/checker.c
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

SRC_PUSH_SWAP = $(addprefix $(SRC_DIR),\
		push_swap.c\
		optimization.c\
		set_index.c\
		sort_insert.c)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

SRC_BASE = $(addprefix $(SRC_DIR),\
		swap.c\
		reverse.c\
		reverse_rotate.c\
		input_read.c)
OBJ_SRC_BASE = $(SRC_BASE:.c=.o)
# SRC_LIB = $(addprefix $(DIR_LIB),\
# 		ft_abs.c\
# 		ft_atoi.c\
# 		ft_bzero.c\
# 		ft_cinstr.c\
# 		ft_count_p.c\
# 		ft_pow.c \
# 		ft_putnstr.c\
# 		ft_strlen.c\
# 		ft_strncpy.c)
# OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
# OBJ_BASE = $(SRC_BASE:.c=.o)
# OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

CHECKER = checker

PUSH_SWAP = push_swap

LIB = libft/libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
HEADER = include/push_swap.h

OBJECTS_DIRECTORY = objects/

all: $(LIB) $(PUSH_SWAP) $(CHECKER) 
# $(PUSH_SWAP) 
# $(OBJ_SRC_BASE)

$(LIB):
	make -C libft/

# $(OBJ_SRC_BASE): $(SRC_BASE)
# $(CHECKER): $(OBJ_CHECKER) $(OBJ_BASE) $(HEADER) $(LIB)
# 	gcc 
# gcc $(OBJ_CHECKER) $(OBJ_BASE) $(LIB) -o $(CHECKER)
# $(PUSH_SWAP): 
# 	$(SRC_PUSH_SWAP)
# 	$(SRC_CHECKER)
# $(OBJECTS_DIRECTORY):
# 	mkdir -p $(OBJECTS_DIRECTORY)
# $(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
# 	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
# %.o: sources/%.c $(HEADER)
# 	gcc -Wall -Wextra -Werror -c $<


$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_SRC_BASE)
	gcc $(OBJ_PUSH_SWAP) $(OBJ_SRC_BASE) $(LIB) -o $(PUSH_SWAP)

$(CHECKER): $(OBJ_CHECKER) $(OBJ_SRC_BASE)
	gcc $(OBJ_CHECKER) $(OBJ_SRC_BASE) $(LIB) -o $(CHECKER)

%.o: source/%.c $(HEADER)
	gcc -c $< -o $@

# $(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_SRC_BASE) $(HEADER) $(LIB)
# 	gcc $(OBJ_PUSH_SWAP) $(OBJ_SRC_BASE) $(LIB) -o $(PUSH_SWAP)
# gcc source/push_swap.c source/code_base.c $(LIB) -o push_swap
# gcc -g source/push_swap.c source/code_base.c $(LIB) -o ps
# $(NAME): $(OBJ) $(LIB)
# 	ar rc $(NAME) $(OBJ) 
# %.o: sources/%.c $(HEADER)
# 	gcc -Wall -Wextra -Werror -c $<
# -Wall -Wextra -Werror
# %.o: source/%.c $(HEADER)
# 	gcc -c $<

clean:
	make clean -C libft
	rm -rf *.o source/*.o

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(LIB)

re: fclean all
