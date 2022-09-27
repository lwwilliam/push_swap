/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:24:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/27 22:04:04 by lwilliam         ###   ########.fr       */
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

void	sort(t_stack *stack, char a_b, char num)
{
	int	i;
	int	j;
	int	min;
	int	x;

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
	x = 0;
	while (x < stack->b_count && num == '1')
	{
		printf("tmp_arr %d\n", stack->tmp_arr[x]);
		x++;
	}
	if (num == '1')
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
	printf(" \033[1;31m median %d   \033[0m\n ", stack->median);
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
	x = 0;
	while (x < stack->arr_count && a_b == 'b')
	{
		if (stack->b[0] >= stack->median)
			pa(stack);
		else
			rb(stack);
		x++;
	}
	free(stack->tmp_arr);
	stack->arr_count -= stack->med_pos;
}

void	check(t_stack *stack)
{
	int	tmp;
	int x;
	int r_w;

	x = 0;
	r_w = 0;
	tmp = stack->arr_count;
	stack->arr_count = stack->a_count;
	sort(stack, 'a', '0');
	while (x != stack->a_count && r_w == 0)
	{
		if (stack->a[x] != stack->tmp_arr[x])
		{
			r_w = 1;
		}
		x++;
	}
	free(stack->tmp_arr);
	stack->arr_count = tmp;
	if (x == stack->a_count && r_w == 0 && stack->b_count == 0)
		exit(0);
}