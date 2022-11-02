/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:00:59 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/02 11:33:50 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(char **av, t_stack *stack)
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
	// if (x != stack->a_count || r_w != 0 || stack->b_count != 0)
	// 	num_check(av, stack);
	// else
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
				write(2, "Error\n", 6);
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
					t_num_a(stack, 1);
				if (stack->a_count == 2)
					two_num(stack, 'a');
				last(stack);
				check(av, stack);
			}
			num_check2(av, stack);
		}
	}
}

void	num_check2(char **av, t_stack *stack)
{
	int	tmp;
	int	x;

	tmp = 0;
	x = 2;
	while (stack->a_count > 3)
		sort(stack, 'a', '1');
	if (stack->a_count == 3)
		t_num_a(stack, 0);
	if (stack->a_count == 2)
		two_num(stack, 'a');
	two_num(stack, 'b');
	if (stack->arr_count > stack->b_count)
		stack->arr_count = stack->b_count;
	tmp = stack->arr_count;
	sort(stack, 'b', '1');
	t_num_a(stack, 1);
	rotate(stack, 'b', tmp - stack->arr_count);
	two_num(stack, 'b');
	stack->arr_count = stack->b_count;
	num_check3(av, stack);
}

void	num_check3(char **av, t_stack *stack)
{
	int	tmp;
	int	x;

	tmp = stack->arr_count;
	check(av, stack);
	sort(stack, 'b', '1');
	t_num_a(stack, 1);
	while (stack->arr_count >= 5)
	{
		sort(stack, 'a', '1');
		t_num_a(stack, 1);
		rotate(stack, 'a', stack->arr_count);
	}
	x = stack->arr_count;
	x_num(stack, 'a', x);
	last(stack);
	stack->arr_count = tmp - stack->arr_count;
	stack->tmp_arr_count++;
	num_check3(av, stack);
}

void	rotate(t_stack *stack, char a_b, int x)
{
	int	tmp;

	tmp = x;
	while (tmp > 0 && a_b == 'b')
	{
		rrb(stack);
		tmp--;
	}
	while (tmp > 0 && a_b == 'a')
	{
		rra(stack);
		tmp--;
	}
}
