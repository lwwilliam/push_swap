/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:11 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/11 21:22:14 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alnum_filter_bonus(char **av, t_bonus *bonus)
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
			alt_f4(1);
		y = (av[x][0] == '-' && ft_strlen(av[x]) > 1);
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1 || ft_isdigit(tmp) == 0)
				alt_f4(1);
		}
	}
	bonus->a_count = (x - 1);
}

void	numto_a_bonus(char **av, t_bonus *bonus)
{
	int		x;
	int		x_a;
	int		*num;

	x = 0;
	x_a = 0;
	num = malloc(sizeof(int) * (bonus->a_count + 1));
	while (av[++x])
	{
		num[x_a] = (int)ft_atoi(av[x]);
		x_a++;
	}
	bonus->a = num;
}

void	dup_check_bonus(int *where, int where_len)
{
	int	x;
	int	y;

	x = 0;
	while (x < where_len)
	{
		y = x + 1;
		while (y < where_len)
		{
			if (where[x] - where[y] == 0)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			y++;
		}
		x++;
	}
}

void	get_oppr(t_bonus *bonus)
{
	char *str;

	str = get_next_line(1);
	printf("test)
}

int	main(int ac, char **av)
{
	t_bonus	bonus;
	char	**tmp;
	char	**arr;
	int		y;
	int		x;

	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		y = 1;
		x = 0;
		arr = ft_split(av[1], ' ');
		tmp = malloc(sizeof(char) * (900 * 900));
		while (arr[x])
			tmp[y++] = arr[x++];
	}
	else
		tmp = av;
	alnum_filter_bonus(tmp, &bonus);
	numto_a_bonus(tmp, &bonus);
	dup_check_bonus(bonus.a, bonus.a_count);
	get_oppr(&bonus);
}
