/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:05:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/13 15:26:05 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_printf("sa\n");
	// print_test(stack, "a after sa", "b after sa");
}

void	sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_printf("sb\n");
	// print_test(stack, "a after sb", "b after sb");
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}
