/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_num.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:31:25 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/26 01:38:54 by lwilliam         ###   ########.fr       */
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
		{
			sa(stack);
		}
	}
}

void	two_num(t_stack *stack, char a_b)
{
	if (stack->a[1] < stack->a[0] && a_b == 'a')
		sa(stack);
	if (stack->b[1] > stack->b[0] && a_b == 'b')
	{
		sb(stack);
		pa(stack);
		pa(stack);
		stack->arr_count += 2;
	}
	else if (stack->b[1] < stack->b[0] && a_b == 'b')
	{
		pa(stack);
		pa(stack);
		stack->arr_count += 2;
	}
}

// void	first_two(t_stack *stack char a_b)
// {
// 	if (stack->a[1] < stack->a[0] && a_b == 'a')
// 		sa(stack);
// }