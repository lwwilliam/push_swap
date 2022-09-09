/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:29:33 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/09 21:01:15 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack)
{
	int	tmp;
	int	count;
	int	*tmp_arr;

	if (stack->b_count == 0)
	{
		stack->b[0] = stack->a[0];
		stack->b_count += 1;
	}
	else
	{
		count = 0;
		tmp = stack->b_count;
		while (tmp >= 0)
		{
			stack->b[tmp + 1] = stack->b[tmp];
			tmp--;
		}
		stack->b[0] = stack->a[0];
		stack->a_count -= 1;
	}
}

void	move_a_up(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	while (tmp < stack->a_count)
	{
		stack->a[tmp + 1] = stack[tmp];
		tmp++;
	}
}
