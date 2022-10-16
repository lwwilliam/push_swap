/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/16 16:55:12 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alt_f4(t_stack *stack)
{
	(void)stack;

	write(2, "Error\n", 6);
	exit(0);
}

void	alnum_filter(char **av, t_stack *stack)
{
	int		x;
	int		y;
	long	num;
	char	tmp;

	x = 0;
	while (av[++x])
	{
		num = ft_atoi(av[x]);
		if (num > 2147483647 || num < -2147483648)
			alt_f4(stack);
		y = 0;
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1 || ft_isdigit(tmp) == 0)
				alt_f4(stack);
		}
	}
	stack->a_count = (x - 1);
	stack->arr_count = stack->a_count;
}

void	numto_a(char **av, t_stack *stack)
{
	int		x;
	int		x_a;
	int		*num;

	x = 0;
	x_a = 0;
	num = malloc(sizeof(int) * (stack->a_count + 1));
	stack->b = malloc(sizeof(int) * (stack->a_count + 1));
	while (av[++x])
	{
		num[x_a] = (int)ft_atoi(av[x]);
		x_a++;
	}
	stack->a = num;
}

void	dup_check(t_stack *stack)
{
	int	x;
	int	y;

	x = 0;
	while (x < stack->a_count)
	{
		y = x + 1;
		while (y < stack->a_count)
		{
			if (stack->a[x] - stack->a[y] == 0)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.b_count = 0;
	stack.run_num = 0;
	stack.run_set = 1;
	if (ac <= 2)
	{
		exit(0);
	}
	alnum_filter(av, &stack);
	numto_a(av, &stack);
	dup_check(&stack);
	num_check(av, &stack);
	check(av, &stack);
	free(stack.a);
}
