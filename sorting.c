/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:24:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/22 16:46:31 by lwilliam         ###   ########.fr       */
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
	while (x < stack->arr_count && a_b == 'a')
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

void	sort(t_stack *stack, char a_b)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	arr_dup(stack, a_b);
	while (i < stack->arr_count)
	{
		min = i;
		j = i + 1;
		while (j < stack->arr_count)
		{
			if (stack->tmp_arr[j] < stack->tmp_arr[min])
				min = j;
			j++;
		}
		swap(&stack->tmp_arr[min], &stack->tmp_arr[i]);
		i++;
	}
	med(stack, a_b);
}

void	med(t_stack *stack, char a_b)
{
	stack->med_pos = stack->arr_count % 2;
	if (stack->med_pos == 1)
		stack->med_pos = (stack->arr_count / 2);
	if (stack->med_pos == 0)
		stack->med_pos = stack->arr_count / 2;
	stack->median = stack->tmp_arr[stack->med_pos];
	printf(" \033[1;31m median %d   \033[m\n ", stack->median);
	pushing(stack, a_b);
	
}

void	pushing(t_stack *stack, char a_b)
{
	int	x;

	x = 0;
	while (x < stack->arr_count && a_b == 'a')
	{
		if (stack->a[0] < stack->median)
			pb(stack);
		else
			ra(stack);
		x++;
	}
	while (x < stack->arr_count && a_b == 'b')
	{
		if (stack->a[0] < stack->median)
			pa(stack);
		else
			rb(stack);
		x++;
	}
	free(stack->tmp_arr);
	stack->arr_count -= stack->med_pos;
}
