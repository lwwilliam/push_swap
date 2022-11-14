/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_num.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:31:25 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:26 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_num_a(t_stack *stack, int tmp)
{
	if (stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2] && tmp == 0)
		ra(stack->a, stack->a_count, 'm');
	if (stack->a[1] < stack->a[0])
		sa(stack->a, 'm');
	if (stack->a[2] < stack->a[0] && tmp == 0)
		rra(stack->a, stack->a_count, 'm');
	if (stack->a[2] < stack->a[1])
	{
		pb(stack);
		sa(stack->a, 'm');
		pa(stack);
		if (stack->a[1] < stack->a[0])
			sa(stack->a, 'm');
	}
}

void	t_num_b(t_stack *stack)
{
	int	x;

	x = 3;
	if (stack->b[1] > stack->b[0])
		sb(stack->b, 'm');
	if (stack->b[2] > stack->b[1])
	{
		pa(stack);
		sb(stack->b, 'm');
		pb(stack);
		if (stack->b[1] > stack->b[0])
			sb(stack->b, 'm');
	}
	while (x-- > 0)
		pa(stack);
}

void	two_num(t_stack *stack, char a_b)
{
	if (stack->a[1] < stack->a[0] && a_b == 'a')
		sa(stack->a, 'm');
	if (a_b == 'b' && stack->b_count > 1)
	{
		if (stack->b[1] > stack->b[0])
			sb(stack->b, 'm');
		pa(stack);
		pa(stack);
		stack->arr_count += 2;
	}
}
//(top == 1) = the first two number;

int	first_two(t_stack *stack)
{
	int	top;
	int	top2;

	top = 0;
	top2 = 0;
	if (stack->b[0] == stack->tmp_arr[stack->b_count - 1]
		|| stack->b[1] == stack->tmp_arr[stack->b_count - 1])
		top = 1;
	if (stack->b[0] == stack->tmp_arr[stack->b_count - 2]
		|| stack->b[1] == stack->tmp_arr[stack->b_count - 2])
		top2 = 1;
	if (top == 1 && top2 == 1)
		return (1);
	else
		return (0);
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
		median(stack, 'b', '1', 4);
		two_num(stack, 'a');
		two_num(stack, 'b');
	}
	if (stack->a_count == 3)
		t_num_a(stack, 0);
	if (stack->a_count == 2)
		two_num(stack, 'a');
	if (stack->a_count == 5 || stack->a_count == 4)
	{
		median(stack, 'a', '1', stack->a_count);
		pushing(stack, 'a');
		if (stack->a_count == 3)
			t_num_a(stack, 0);
		two_num(stack, 'a');
		two_num(stack, 'b');
	}
}

// void	x_num(t_stack *stack, char a_b, int count)
// {
// 	if (count == 2 && a_b == 'a')
// 		two_num(stack, 'a');
// 	if (count == 3 && a_b == 'a')
// 		t_num_a(stack, '1');
// 	if ((count == 5 || count == 4) && a_b == 'a')
// 	{
// 		median(stack, 'a', '1', count);
// 		rotate(stack, 'a', 2);
// 		if (count == 5)
// 		{
// 			rotate(stack, 'a', 1);
// 			t_num_a(stack, 0);
// 		}
// 		two_num(stack, 'a');
// 		two_num(stack, 'b');
// 	}
// 	if (count == 2 && a_b == 'b')
// 		two_num(stack, 'b');
// 	if (count == 3 && a_b == 'b')
// 		t_num_a(stack, '1');
// 	if ((count == 5 || count == 4) && a_b == 'b')
// 	{
// 		median(stack, 'b', '1', count);
// 		if (count == 5)
// 			t_num_b(stack);
// 		two_num(stack, 'a');
// 		two_num(stack, 'b');
// 	}
// }
