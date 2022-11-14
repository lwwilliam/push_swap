/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:10:02 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 16:40:53 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char a_b, int x)
{
	int	tmp;

	tmp = x;
	while (tmp > 0 && a_b == 'b')
	{
		rrb(stack->b, stack->b_count, 'm');
		tmp--;
	}
	while (tmp > 0 && a_b == 'a')
	{
		rra(stack->a, stack->a_count, 'm');
		tmp--;
	}
}

void	alt_f4(int num)
{
	(void)num;
	write(2, "Error\n", 6);
	exit(0);
}

void	median_utils(t_stack *stack, int len)
{
	stack->arr_count = len;
	med(stack);
	free(stack->tmp_arr);
}

void	push_b_util(t_stack *stack)
{
	if (stack->b[0] >= stack->median)
		pa(stack);
	else
	{
		rb(stack->b, stack->b_count, 'm');
		stack->rb_count++;
	}
}

void	init_funct(t_stack *stack)
{
	stack->b_count = 0;
	stack->run_num = 0;
	stack->run_set = 1;
	stack->error = 0;
}
