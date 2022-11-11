# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 18:10:19 by lwilliam          #+#    #+#              #
#    Updated: 2022/11/11 21:17:24 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

NAME_BONUS = checker.a

SRC = push_swap.c swap.c push.c rotate.c rev_rotate.c sorting.c x_num.c check.c utils.c ./libft_printf/gnl/*.c

BONUS_SRC = checker.c swap.c push.c rotate.c rev_rotate.c sorting.c x_num.c check.c utils.c ./libft_printf/gnl/*.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) :
	make libft
	$(CC) $(CFLAGS) $(SRC) $(NAME) -o push_swap

$(NAME_BONUS) :
	make libft_bonus
	$(CC) $(CFLAGS) $(BONUS_SRC) $(NAME_BONUS) -o checker

libft:
	make -C libft_printf
	cp libft_printf/libft.a .
	mv libft.a $(NAME)

libft_bonus:
	make -C libft_printf
	cp libft_printf/libft.a .
	mv libft.a $(NAME_BONUS)

clean :
	rm -f *.o
	make clean -C libft_printf

fclean : clean
	rm -f $(NAME) push_swap
	rm -f $(NAME_BONUS) checker
	make fclean -C libft_printf

re : fclean all
	make re -C libft_printf
