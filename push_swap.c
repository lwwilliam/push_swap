/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/02 12:04:12 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alt_f4(t_stack *stack)
{
	(void)stack;
	write(2, "Error\n", 6);
	exit(0);
}

void	alnum_filter(char **av, t_stack *stack)
{
	int		x;
	int		y;
	long	num;
	char	tmp;

	x = 0;
	stack->b_count = 0;
	stack->run_num = 0;
	stack->run_set = 1;
	while (av[++x])
	{
		num = ft_atoi(av[x]);
		if (num > 2147483647 || num < -2147483648)
			alt_f4(stack);
		y = (av[x][0] == '-' && ft_strlen(av[x]) > 1);
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1 || ft_isdigit(tmp) == 0)
				alt_f4(stack);
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
	// print_test(stack, "a at start", "b at start");
}

// void	print_test(t_stack *stack, char *where_a, char *where_b)
// {
// 	int	y;

// 	y = 0;
// 	while (y < stack->a_count)
// 	{
// 		printf("\033[32m| %s: %d \033[0m", where_a, stack->a[y++]);
// 	}
// 	printf("\n\n");
// 	y = 0;
// 	while (y < stack->b_count)
// 	{
// 		printf("\033[34m| %s: %d \033[0m", where_b, stack->b[y++]);
// 	}
// 	printf("\n\n");
// }

int	main(int ac, char **av)
{
	t_stack	stack;
	char	**tmp;
	char	**arr;
	int		y;
	int		x;

	tmp = malloc(sizeof(char) * (900 * 900));
	if (ac == 1)
		alt_f4(&stack);
	if (ac == 2)
	{
		y = 1;
		x = 0;
		arr = ft_split(av[1], ' ');
		while (arr[x])
			tmp[y++] = arr[x++];
	}
	else
		tmp = av;
	alnum_filter(tmp, &stack);
	numto_a(tmp, &stack);
	dup_check(&stack);
	num_check(tmp, &stack);
	check(tmp, &stack);
	free(stack.a);
}
