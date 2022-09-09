/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/09 18:41:15 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alt_f4(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	num_check(char **av, t_stack *stack)
{
	int		bfr;
	int		aft;
	int		x;

	x = 1;
	while (av[x + 1])
	{
		bfr = ft_atoi(av[x]);
		x++;
		aft = ft_atoi(av[x]);
		if (aft - bfr < 0)
			sa(stack);
	}
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
			alt_f4("Some arguments contains invalid integer!");
		y = 0;
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1)
				alt_f4("Some arguments aren't integer!");
		}
	}
	stack->a_count = (x - 1);
}

void	numto_a(char **av, t_stack *stack)
{
	int		x;
	int		x_a;
	int		*num;
	int		y;

	x = 0;
	x_a = 0;
	num = malloc(sizeof(int) * (stack->a_count));
	while (av[++x])
	{
		num[x_a] = (int)ft_atoi(av[x]);
		x_a++;
	}
	stack->a = num;
	free(num);
	y = 0;
	while (y < stack->a_count)
	{
		printf("| before sa: %d ", stack->a[y++]);
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		x;

	x = 0;
	stack.b = 0;
	if (ac < 2)
		ft_printf("Arguments is less than 2\n");
	alnum_filter(av, &stack);
	numto_a(av, &stack);
	num_check(av, &stack);
}
