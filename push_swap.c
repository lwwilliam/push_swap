/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/27 22:08:50 by lwilliam         ###   ########.fr       */
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
			if (stack->a_count == 3)
				t_num_a(stack);
			check(stack);
			num_check2(av, stack);
		}
	}
}

void	num_check2(char **av, t_stack *stack)
{
	int	tmp;
	
	tmp = 0;
	
	if (stack->fst_run == 1)
		printf(" \033[1;31m 2nd run \033[0m\n ");
	sort(stack, 'a', '1');
	while (stack->a_count > 3 && stack->fst_run == 0)
		sort(stack, 'a', '1');
	if (stack->a_count == 3 || stack->fst_run == 1)
	{
		tmp = stack->a_count - stack->arr_count;
		while (tmp-- > 0 && stack->fst_run == 1)
		{
			ra(stack);
		}
		t_num_a(stack);
	}
	two_num(stack, 'a');
	two_num(stack, 'b');
	check(stack);
	tmp = stack->b_count - stack->arr_count;
	printf("here???\n");
	sort(stack, 'b', '1');
	if (stack->fst_run == 1)
	{
		t_num_a(stack);
		two_num(stack, 'a');
		two_num(stack, 'b');
		if (stack->b_count > 0)
		{
			pa(stack);
			two_num(stack, 'a');
		}
	}
	if (stack->fst_run == 1)
		exit(0);
	while (tmp-- > 0)
		rb(stack);
	two_num(stack, 'a');
	two_num(stack, 'b');
	check(stack);
	stack->arr_count = stack->b_count;
	sort(stack, 'b', '1');
	stack->fst_run = 1;
	num_check(av, stack);
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
	stack.fst_run = 0;
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
