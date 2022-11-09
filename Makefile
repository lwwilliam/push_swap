# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 18:10:19 by lwilliam          #+#    #+#              #
#    Updated: 2022/11/09 12:54:23 by lwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = push_swap.c swap.c push.c rotate.c rev_rotate.c sorting.c x_num.c check.c utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	make libft
	$(CC) $(CFLAGS) $(SRC) $(NAME) -o push_swap 

libft:
	make -C libft_printf
	cp libft_printf/libft.a .
	mv libft.a $(NAME)

clean :
	rm -f *.o
	make clean -C libft_printf

fclean : clean
	rm -f $(NAME) push_swap
	make fclean -C libft_printf

re : fclean all
	make re -C libft_printf

.PHONY : $(NAME)