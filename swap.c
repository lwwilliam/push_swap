/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:05:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/21 23:23:47 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	print_test(stack, "a after sa", "b after sa");
}

void	sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	print_test(stack, "a after sb", "b after sb");
}

void	ss(t_stack *stack)
{
	printf("\033[1;31m");
	printf("start of ss\n\n");
	printf("\033[0m");
	sa(stack);
	sb(stack);
	printf("\033[1;31m");
	printf("end of ss\n\n");
	printf("\033[0m");
}
