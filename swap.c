/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:05:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/10 15:16:41 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;
	int	y;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	y = 0;
	print_test(stack, "a after sa", "b after sa");
}

void	sb(t_stack *stack)
{
	int	tmp;
	int	y;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	y = 0;
	print_test(stack, "a after sb", "b after sb");
}

void	ss(t_stack *stack)
{
	printf("start of ss\n");
	sa(stack);
	sb(stack);
	printf("end of ss\n");
}
