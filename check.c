/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:00:59 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/12 18:31:04 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(t_stack *stack)
{
	int	tmp;
	int	x;
	int	r_w;

	x = 0;
	r_w = 0;
	tmp = stack->arr_count;
	stack->arr_count = stack->a_count;
	sort(stack, 'a', '0');
	while (x != stack->a_count && r_w == 0)
	{
		if (stack->a[x] != stack->tmp_arr[x])
		{
			r_w = 1;
		}
		x++;
	}
	free(stack->tmp_arr);
	stack->arr_count = tmp;
	if (x == stack->a_count && r_w == 0 && stack->b_count == 0)
		exit(0);
}

void	dup_check(t_stack *stack)
{
	int	x;
	int	y;

	x = 0;
	while (x < stack->a_count)
	{
		y = x + 1;
		while (y < stack->a_count)
		{
			if (stack->a[x] - stack->a[y] == 0)
			{
				ft_printf("ERROR! Duplicated number = %d\n", stack->a[y]);
				exit(0);
			}
			y++;
		}
		x++;
	}
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
			if (stack->a_count <= 5)
			{
				if (stack->a_count == 3)
					t_num_a(stack);
				if (stack->a_count == 2)
					two_num(stack, 'a');
			}
			check(stack);
			num_check2(av, stack);
		}
	}
}

void	num_check2(char **av, t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (stack->run_num > 1)
		printf("\033[1;31mrun %d\033[0m\n", stack->run_num);
	sort(stack, 'a', '1');
	while (stack->a_count > 3 && stack->run_set == 0)
	{
		sort(stack, 'a', '1');
	}
	if (stack->a_count == 3 || stack->run_set == 1)
	{
		tmp = stack->a_count - stack->arr_count;
		while (tmp-- > 0 && stack->run_set == 1)
		{
			ra(stack);
		}
		t_num_a(stack);
	}
	two_num(stack, 'a');
	two_num(stack, 'b');
	check(stack);
	tmp = stack->b_count - stack->arr_count;
	if (stack->b_count > 1)
		sort(stack, 'b', '1');
	t_num_a(stack);
	if (stack->run_num > 1)
	{
		t_num_a(stack);
		two_num(stack, 'a');
		two_num(stack, 'b');
		if (stack->b_count > 0)
		{
			pa(stack);
			t_num_a(stack);
		}
	}
	if (stack->run_num == 4)
	{
		stack->run_num++;
		stack->run_set = 0;
	}
	if (stack->run_num > 1)
	{
		stack->run_num++;
		check(stack);
		num_check(av, stack);
	}
	while (tmp-- > 0)
		rb(stack);
	two_num(stack, 'a');
	two_num(stack, 'b');
	check(stack);
	stack->arr_count = stack->b_count;
	sort(stack, 'b', '1');
	stack->run_num++;
	stack->run_set = 1;
	check(stack);
	num_check(av, stack);
}
