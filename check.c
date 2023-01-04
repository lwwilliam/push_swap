/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:00:59 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:20:39 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(char **av, t_stack *stack, int len, int ac)
{
	int	x;
	int	r_w;

	x = 0;
	r_w = 0;
	len = stack->a_count;
	median(stack, 'a', '0', len);
	while (x != stack->a_count && r_w == 0)
	{
		if (stack->a[x] != stack->tmp_arr[x])
		{
			r_w = 1;
		}
		x++;
	}
	free(stack->b);
	free(stack->a);
	if (x == stack->a_count && r_w == 0 && stack->b_count == 0)
	{
		if (ac < 3)
			free_funct(av);
		exit(0);
	}
}

void	num_check(char **av, t_stack *stack, int ac)
{
	int		bfr;
	int		aft;
	int		x;
	int		len;

	x = 1;
	len = stack->arr_count;
	stack->tmp_arr_count = 0;
	while (av[x + 1])
	{
		bfr = ft_atoi(av[x]);
		x++;
		aft = ft_atoi(av[x]);
		if (aft - bfr < 0 || (aft < 0 && bfr > 0))
		{
			if (stack->a_count <= 5)
			{
				last(stack);
				check(av, stack, stack->a_count, ac);
			}
			stack->error = 1;
		}
	}
	if (stack->error == 1)
		quick_sort_a(av, stack, len);
}

void	quick_sort_a(char **av, t_stack *stack, int len)
{
	median(stack, 'a', '1', len);
	if (len == 2)
		two_num(stack, 'a');
	if (len == 3)
		t_num_a(stack, 1);
	if (len > 3)
	{
		pushing(stack, 'a');
		rotate(stack, 'a', stack->ra_count);
		quick_sort_a(av, stack, (len / 2)
			+ (len % 2));
		quick_sort_b(av, stack, (len / 2));
	}
}

void	quick_sort_b(char **av, t_stack *stack, int len)
{
	median(stack, 'b', '1', len);
	if (len == 2)
		two_num(stack, 'b');
	if (len == 3)
	{
		t_num_b(stack);
		pushing(stack, 'b');
		rotate(stack, 'b', stack->rb_count);
	}
	if (len > 3)
	{
		pushing(stack, 'b');
		rotate(stack, 'b', stack->rb_count);
		quick_sort_a(av, stack, (len / 2)
			+ (len % 2));
		quick_sort_b(av, stack, (len / 2));
	}
}

void	free_funct(char **av)
{
	char	**tmp;

	tmp = av;
	while (tmp && *tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(av);
}
