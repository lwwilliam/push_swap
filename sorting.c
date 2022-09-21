/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:24:23 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/21 17:41:54 by lwilliam         ###   ########.fr       */
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

// void	divide(t_stack *stack)
// {
// 	int	half;
// 	int	tmp;
// 	int	x;
// 	int	y;

// 	half = stack->a_count / 2;
// 	tmp = 0;
// 	x = 0;
// 	y = 0;
// 	stack->tmp_a = malloc(sizeof(int) * (stack->a_count));
// 	while (half > 0)
// 	{
// 		x = 0;
// 		while (x < stack->a_count)
// 		{
// 			if (stack->a[x] == tmp)
// 			{
// 				stack->tmp_a[y] = stack->a[x];
// 				y++;
// 				half--;
// 			}
// 			x++;
// 		}
// 		tmp++;
// 	}
// 	while (stack->b_count < 7)
// 	{
// 		push(stack);
// 	}
// }

// void	push(t_stack *stack)
// {
// 	int	x;
// 	int	half;
// 	int	tmp;

// 	half = stack->a_count / 2;
// 	tmp = 0;
// 	x = 0;
// 	while (x < half)
// 	{
// 		printf("currrnt a  : %d\n", stack->a[0]);
// 		printf("currrnt tmp: %d\n", stack->tmp_a[x]);
// 		if (stack->tmp_a[x] == stack->a[0])
// 		{
// 			x = 0;
// 			pb(stack);
// 			x = 0;
// 			push(stack);
// 		}
// 		x++;
// 	}
// 	if (stack->tmp_a[x] != stack->a[0])
// 	{
// 		x = 0;
// 		ra(stack);
// 	}
// }
void	arr_dup(t_stack *stack)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	stack->tmp_a = malloc(sizeof(int) * (stack->a_count + 1));
	while (x < stack->a_count)
	{
		stack->tmp_a[y] = stack->a[x];
		printf(stack->tmp_a, )
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

void	sort(t_stack *stack)
{
	int	i;
	int	j;
	int	min;
	int	y;

	i = 0;
	j = 0;
	y = 0;
	arr_dup(stack);
	while (i < stack->a_count)
	{
		min = i;
		j = i + 1;
		while (j < stack->a_count)
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
	int	tmp;

	tmp = stack->a_count % 2;
	if (tmp == 1)
		tmp = stack->a_count / 2;
	if (tmp == 0)
		tmp = stack->a_count / 2;
	printf("test  %d %d\n", tmp, stack->a[3]);
	stack->median = stack->a[tmp - 2];
	pushing(stack);
}

void	pushing(t_stack *stack)
{
	int	x;

	x = 0;
	while (x < 15)
	{
		printf("%d   %d   %d\n", stack->a[0], stack->median, stack->a_count);
		if (stack->a[0] <= stack->median)
			pb(stack);
		else
			ra(stack);
		x++;
	}
	exit(0);
}
