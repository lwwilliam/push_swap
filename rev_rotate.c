/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:39:51 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/10 14:56:09 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	last;

	last = stack->a[stack->a_count - 1];
	tmp = stack->a_count;
	while (tmp > -1)
	{
		stack->a[tmp + 1] = stack->a[tmp];
		tmp--;
	}
	stack->a[0] = last;
	print_test(stack, "a after rra", "b after rra");
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	last;

	last = stack->b[stack->b_count - 1];
	tmp = stack->b_count;
	while (tmp > -1)
	{
		stack->b[tmp + 1] = stack->b[tmp];
		tmp--;
	}
	stack->b[0] = last;
	print_test(stack, "a after rrb", "b after rrb");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	printf("rrr is called\n");
}
