/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_num.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:31:25 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/27 22:10:31 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_num_a(t_stack *stack)
{
	if (stack->a[1] < stack->a[0])
		sa(stack);
	if (stack->a[2] < stack->a[1])
	{
		pb(stack);
		sa(stack);
		pa(stack);
		if (stack->a[1] < stack->a[0])
			sa(stack);
	}
	if (stack->b_count == 0)
		exit(0);
}

void	two_num(t_stack *stack, char a_b)
{
	int tmp;

	if (stack->a[1] < stack->a[0] && a_b == 'a')
		sa(stack);
	tmp = stack->arr_count;
	stack->arr_count = stack->b_count;
	sort(stack, 'b', '0');
	stack->arr_count = tmp;
	if (a_b == 'b' && (stack->b[0] == stack->tmp_arr[stack->b_count - 1] ||
		stack->b[1] == stack->tmp_arr[stack->b_count - 1]) &&
		stack->b_count > 1)
	{
		if (stack->b[1] > stack->b[0])
			sb(stack);
		pa(stack);
		pa(stack);
		stack->arr_count += 2;
		free(stack->tmp_arr);
	}
}
