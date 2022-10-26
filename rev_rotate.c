/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:39:51 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/26 13:28:25 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	tmp;
	int	last;

	last = stack->a[stack->a_count - 1];
	tmp = stack->a_count - 1;
	while (tmp > -1)
	{
		stack->a[tmp + 1] = stack->a[tmp];
		tmp--;
	}
	stack->a[0] = last;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	last;

	last = stack->b[stack->b_count - 1];
	tmp = stack->b_count - 1;
	while (tmp > -1)
	{
		stack->b[tmp + 1] = stack->b[tmp];
		tmp--;
	}
	stack->b[0] = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
}
