/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:22:15 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/14 18:04:07 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	tmp;
	int	first;

	tmp = 0;
	first = stack->a[0];
	while (tmp < stack->a_count - 1)
	{
		stack->a[tmp] = stack->a[tmp + 1];
		tmp++;
	}
	stack->a[tmp] = first;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	tmp;
	int	first;

	tmp = 0;
	first = stack->b[0];
	while (tmp < stack->b_count - 1)
	{
		stack->b[tmp] = stack->b[tmp + 1];
		tmp++;
	}
	stack->b[tmp] = first;
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_printf("rr\n");
}
