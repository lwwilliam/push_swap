/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:24:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 16:39:28 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_dup(t_stack *stack, char a_b)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	stack->tmp_arr = malloc(sizeof(int) * (stack->arr_count + 1));
	while (x < stack->arr_count && a_b == 'a')
	{
		stack->tmp_arr[y] = stack->a[x];
		x++;
		y++;
	}
	while (x < stack->arr_count && a_b == 'b')
	{
		stack->tmp_arr[y] = stack->b[x];
		x++;
		y++;
	}
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	median(t_stack *stack, char a_b, char num, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	stack->arr_count = len;
	arr_dup(stack, a_b);
	while (i < len)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (stack->tmp_arr[j] < stack->tmp_arr[min])
				min = j;
			j++;
		}
		swap(&stack->tmp_arr[min], &stack->tmp_arr[i]);
		i++;
	}
	if (num == '1')
		median_utils(stack, len);
}

void	med(t_stack *stack)
{
	stack->med_pos = stack->arr_count % 2;
	if (stack->med_pos == 1)
		stack->med_pos = (stack->arr_count / 2);
	if (stack->med_pos == 0)
		stack->med_pos = stack->arr_count / 2;
	stack->median = stack->tmp_arr[stack->med_pos];
}

void	pushing(t_stack *stack, char a_b)
{
	int	x;

	x = 0;
	stack->ra_count = 0;
	stack->rb_count = 0;
	while (x < stack->arr_count && a_b == 'a')
	{
		if (stack->a[0] < stack->median)
			pb(stack);
		else
		{
			ra(stack->a, stack->a_count, 'm');
			stack->ra_count++;
		}
		x++;
	}
	x = 0;
	while (x < stack->arr_count && a_b == 'b')
	{
		push_b_util(stack);
		x++;
	}
}
