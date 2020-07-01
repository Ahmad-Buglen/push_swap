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

SRC_PUSH_SWAP = push_swap.c optimization.c set_index.c sort_insert.c

SRC_BASE = swap.c reverse.c reverse_rotete.c read_input.c

SRC_CHECKER = checker.c

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

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

OBJ_BASE = $(SRC_BASE:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

CHECKER = checker

PUSH_SWAP = push_swap

LIB = libft/libft.a

HEADER = include/push_swap.h

all: $(LIB) $(CHECKER) $(SORPUSH_SWAPT)

$(LIB):  libft/libft.h
	make -C libft

$(CHECKER): $(OBJ_CHECKER) $(OBJ_BASE) $(HEADER) $(LIB)
	gcc 
	# gcc $(OBJ_CHECKER) $(OBJ_BASE) $(LIB) -o $(CHECKER)

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_BASE) $(HEADER) $(LIB)
	gcc $(OBJ_PUSH_SWAP) $(OBJ_BASE) $(LIB) -o $(PUSH_SWAP)
	# gcc source/push_swap.c source/code_base.c $(LIB) -o push_swap
	# gcc -g source/push_swap.c source/code_base.c $(LIB) -o ps

# $(NAME): $(OBJ) $(LIB)
# 	ar rc $(NAME) $(OBJ) 

%.o: sources/%.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $<
# -Wall -Wextra -Werror
# %.o: source/%.c $(HEADER)
# 	gcc -c $<

clean:
	make clean -C libft
	rm -rf *.o

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP) $(LIB)

re: fclean all
