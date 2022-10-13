/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:00:59 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/13 15:15:52 by lwilliam         ###   ########.fr       */
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
	{
		ft_printf("sorted\n");
		exit(0);
	}
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
			if (stack->a_count < 5)
			{
				if (stack->a_count == 3)
					t_num_a(stack);
				if (stack->a_count == 2)
					two_num(stack, 'a');
			}
			num_check2(av, stack);
		}
	}
}

void	num_check2(char **av, t_stack *stack)
{
	int	x;
	int tmp;

	x = 0;
	tmp = stack->a_count - 5;
	while (stack->a_count > 5 && stack->run_num == 0)
	{
		stack->arr_count = stack->a_count;
		sort(stack, 'a', '0');
		while (x < stack->arr_count)
		{
			if (stack->a[0] < stack->tmp_arr[tmp])
				pb(stack);
			else
				ra(stack);
			x++;
		}
		free(stack->tmp_arr);
		stack->arr_count = 5;
		sort(stack, 'a', '1');
		t_num_a(stack);
		two_num(stack, 'b');
	}
	x = 0;
	stack->run_num = 1;
	tmp = stack->b_count - 5;
	while (stack->b_count >= 5)
	{
		stack->arr_count = stack->b_count;
		sort(stack, 'b', '0');
		while (x < stack->arr_count)
		{
			if (stack->b[0] >= stack->tmp_arr[tmp])
				pa(stack);
			else
				rb(stack);
			x++;
		}
		free(stack->tmp_arr);
		stack->arr_count = 5;
		sort(stack, 'a', '1');
		tmp = 5 * stack->run_set;
		while (tmp-- > 0)
			ra(stack);
		t_num_a(stack);
		two_num(stack, 'b');
		stack->run_set++;
		num_check2(av, stack);
	}
	last(stack);
	check(stack);
}

void	last(t_stack *stack)
{
	if (stack->b_count == 1)
		pa(stack);
	if (stack->b_count == 2)
		two_num(stack, 'b');
	if (stack->b_count == 3)
		t_num_b(stack);
	if (stack->b_count == 4)
	{
		sort(stack, 'b', '1');
		two_num(stack, 'b');
		two_num(stack, 'a');
	}
}
