/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/29 15:02:35 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alnum_filter(char **av, t_stack *stack)
{
	int		x;
	int		y;
	long	num;
	char	tmp;

	x = 0;
	while (av[++x])
	{
		num = ft_atoi(av[x]);
		if (num > 2147483647 || num < -2147483648)
			alt_f4(1);
		y = (av[x][0] == '-' && ft_strlen(av[x]) > 1);
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1 || ft_isdigit(tmp) == 0)
				alt_f4(1);
		}
	}
	stack->a_count = (x - 1);
	stack->arr_count = stack->a_count;
}

void	numto_a(char **av, t_stack *stack)
{
	int		x;
	int		x_a;
	int		*num;

	x = 0;
	x_a = 0;
	num = malloc(sizeof(int) * (stack->a_count + 1));
	stack->b = malloc(sizeof(int) * (stack->a_count + 1));
	while (av[++x])
	{
		num[x_a] = (int)ft_atoi(av[x]);
		x_a++;
	}
	stack->a = num;
}

void	dup_check(int *where, int where_len)
{
	int	x;
	int	y;

	x = 0;
	while (x < where_len)
	{
		y = x + 1;
		while (y < where_len)
		{
			if (where[x] - where[y] == 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			y++;
		}
		x++;
	}
}

// void	print_test(t_stack *stack, char *where_a, char *where_b)
// {
// 	int	y;

// 	y = 0;
// 	while (y < stack->a_count)
// 	{
// 		printf("\033[32m| %s: %d \033[0m", where_a, stack->a[y++]);
// 	}
// 	printf("\nlen: %d Array= %d \n\n", stack->a_count, stack->tmp_arr_count);
// 	y = 0;
// 	while (y < stack->b_count)
// 	{
// 		printf("\033[34m| %s: %d \033[0m", where_b, stack->b[y++]);
// 	}
// 	printf("\nlen: %d Array= %d\n\n", stack->b_count, stack->tmp_arr_count);
// }

int	main(int ac, char **av)
{
	t_stack	stack;
	char	**tmp;
	char	**arr;
	int		y;
	int		x;

	if (ac == 1)
		exit(1);
	if (ac == 2)
	{
		y = 1;
		x = 0;
		arr = ft_split(av[1], ' ');
		tmp = malloc(sizeof(char) * (900 * 900));
		while (arr[x])
			tmp[y++] = arr[x++];
	}
	else
		tmp = av;
	init_funct(&stack);
	alnum_filter(tmp, &stack);
	numto_a(tmp, &stack);
	dup_check(stack.a, stack.a_count);
	num_check(tmp, &stack, ac);
	check(tmp, &stack, stack.a_count, ac);
}
