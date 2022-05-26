# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etisha <etisha@student.21-school.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 12:25:54 by etisha            #+#    #+#              #
#    Updated: 2022/05/06 12:25:57 by etisha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

HEADER_BONUS = checker.h

NAME = push_swap

NAME_BONUS = checker

SRC_FILES =	push_swap.c ps_work_with_stack.c ps_strlen.c ps_split.c \
			ps_presort.c ps_instructions_a.c ps_instructions_ab.c \
			ps_instructions_b.c ps_forsort.c ps_exam.c ps_free_memory.c

SRC_BONUS = checker.c ch_work_with_stack.c ch_utils.c ch_split.c \
			ch_instructions_b.c ch_instructions_ab.c ch_instructions_a.c \
			ch_get_next_line.c ch_get_next_line_utils.c ch_exam.c

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus:
	@make NAME="$(NAME_BONUS)" HEADER="$(HEADER_BONUS)" \
	SRC_FILES="$(SRC_BONUS)" all

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
