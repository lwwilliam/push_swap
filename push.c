/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:29:33 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/27 10:25:52 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack)
{
	int	tmp;

	if (stack->b_count == 0)
	{
		stack->b[0] = stack->a[0];
		stack->b_count += 1;
		move_a_up(stack);
	}
	else
	{
		tmp = stack->b_count;
		while (tmp >= 0)
		{
			stack->b[tmp + 1] = stack->b[tmp];
			tmp--;
		}
		stack->b_count += 1;
		stack->b[0] = stack->a[0];
		move_a_up(stack);
	}
	ft_printf("pb\n");
}

void	move_a_up(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	stack->a_count -= 1;
	while (tmp < stack->a_count)
	{
		stack->a[tmp] = stack->a[tmp + 1];
		tmp++;
	}
}

void	pa(t_stack *stack)
{
	int	tmp;

	if (stack->a_count == 0)
	{
		stack->a[0] = stack->b[0];
		stack->a_count += 1;
		move_b_up(stack);
	}
	else
	{
		tmp = stack->a_count;
		while (tmp >= 0)
		{
			stack->a[tmp + 1] = stack->a[tmp];
			tmp--;
		}
		stack->a_count += 1;
		stack->a[0] = stack->b[0];
		move_b_up(stack);
	}
	ft_printf("pa\n");
}

void	move_b_up(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	stack->b_count -= 1;
	while (tmp < stack->b_count)
	{
		stack->b[tmp] = stack->b[tmp + 1];
		tmp++;
	}
}
