/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:24:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/22 00:08:34 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_num(t_stack *stack)
{
	if (stack->a[1] < stack->a[0])
		sa(stack);
	if (stack->a[2] < stack->a[1])
	{
		pb(stack);
		ra(stack);
		pa(stack);
		if (stack->a[1] < stack->a[0])
		{
			sa(stack);
		}
	}
}

void	arr_dup(t_stack *stack)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	stack->tmp_a = malloc(sizeof(int) * (stack->arr_count + 1));
	while (x < stack->arr_count)
	{
		stack->tmp_a[y] = stack->a[x];
		x++;
		y++;
	}
	printf("num: %d %d \n", stack->tmp_a[1], stack->a[1]);
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	sort(t_stack *stack)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	arr_dup(stack);
	while (i < stack->arr_count)
	{
		min = i;
		j = i + 1;
		while (j < stack->arr_count)
		{
			if (stack->tmp_a[j] < stack->tmp_a[min])
				min = j;
			j++;
		}
		swap(&stack->tmp_a[min], &stack->tmp_a[i]);
		i++;
	}
	med(stack);
}

void	med(t_stack *stack)
{
	stack->med_pos = stack->arr_count % 2;
	if (stack->med_pos == 1)
		stack->med_pos = stack->arr_count / 2;
	if (stack->med_pos == 0)
		stack->med_pos = stack->arr_count / 2;
	stack->median = stack->tmp_a[stack->med_pos - 1];
	pushing(stack);
	
}

void	pushing(t_stack *stack)
{
	int	x;

	x = 0;
	while (x < stack->arr_count)
	{
		if (stack->a[0] <= stack->median)
			pb(stack);
		else
			ra(stack);
		x++;
	}
	free(stack->tmp_a);
	stack->arr_count -= stack->med_pos;
}
