/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/22 16:23:03 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alt_f4(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	num_check(char **av, t_stack *stack)
{
	int		bfr;
	int		aft;
	int		x;

	x = 1;
	while (av[x + 1])
	{
		bfr = ft_atoi(av[x]);
		x++;
		aft = ft_atoi(av[x]);
		if (aft - bfr < 0)
		{
			while (stack->a_count > 3)
				sort(stack, 'a');
			if (stack->a_count == 3)
			{
				t_num_a(stack);
				two_num(stack, 'a');
				two_num(stack, 'b');
			}
			else if (stack->a_count == 2)
			{
				two_num(stack, 'a');
				two_num(stack, 'b');
			}
			exit(0);
		}
	}
}

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
			alt_f4("Some arguments contains invalid integer!");
		y = 0;
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1)
				alt_f4("Some arguments aren't integer!");
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
	print_test(stack, "a at start", "b at start");
}

void	print_test(t_stack *stack, char *where_a, char *where_b)
{
	int	y;

	y = 0;
	while (y < stack->a_count)
	{
		printf("| %s: %d ", where_a, stack->a[y++]);
	}
	printf("\n\n");
	y = 0;
	while (y < stack->b_count)
	{
		printf("| %s: %d ", where_b, stack->b[y++]);
	}
	printf("\n\n");
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.b_count = 0;
	if (ac < 2)
		ft_printf("Arguments is less than 2\n");
	alnum_filter(av, &stack);
	numto_a(av, &stack);
	num_check(av, &stack);
	print_test(&stack, "a at the end", "b at the end");
	free(stack.a);
	free(stack.b);
	// system("leaks push_swap");
}
