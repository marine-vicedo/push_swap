# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 17:25:07 by mvicedo           #+#    #+#              #
#    Updated: 2022/10/11 13:02:46 by mvicedo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

BONUS_SRC_DIR = bonus_src/
BONUS_OBJ_DIR = bonus_obj/

SRC =  main.c push_swap.c parsing.c \
big_sort.c little_sort.c \
index.c position.c cost.c rotations.c \
push_op.c rotate_op.c rev_rotate_op.c \
swap_op.c utils.c linked_lists.c \

BONUS_SRC = checker.c checker_utils.c \
do_instructions.c free.c ft_split.c \
parsing.c push_op.c read_instructions.c \
rev_rotate_op.c rotate_op.c swap_op.c \
stack_a.c utils.c \

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))
HEADER	= -I ./header/

BONUS_SRCS	= $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC))
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJS	= $(addprefix $(BONUS_OBJ_DIR), $(BONUS_OBJ))
BONUS_HEADER = -I ./header_bonus/

all: $(OBJ_DIR) $(NAME)

bonus : $(BONUS_OBJ_DIR) $(NAME_BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ 

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	$(CC) $(CFLAGS) $(BONUS_HEADER) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir $(BONUS_OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all bonus

rebonus : fclean bonus

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l



bonus_test2:		$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

bonus_test3:		$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

bonus_test5:		$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

bonus_test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

bonus_test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

bonus_test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l



.PHONY: all clean fclean re rebonus test2 test3 test5 test100 test500 test1000

