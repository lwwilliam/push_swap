/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:05:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/09 18:39:25 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_line(t_stack *stack, char a_or_b);

void	sa(t_stack *stack)
{
	int	tmp;
	int	y;

	check_line(stack, 'a');
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	y = 0;
	while (y < stack->a_count)
	{
		printf("| after sa: %d ", stack->a[y++]);
	}
	printf("\n");
}

void	sb(t_stack *stack)
{
	int	tmp;
	int	y;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	y = 0;
	while (y < stack->a_count)
	{
		printf("| after sb: %d ", stack->b[y++]);
	}
	printf("\n");
}
