/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:38:24 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:47:32 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_check(t_bonus *bonus, int len)
{
	int	x;
	int	r_w;

	x = 0;
	r_w = 0;
	median_bonus(bonus, len);
	while (x != bonus->a_count && r_w == 0)
	{
		if (bonus->a[x] != bonus->tmp_arr[x])
			r_w = 1;
		x++;
	}
	free(bonus->b);
	free(bonus->tmp_arr);
	if (x == bonus->a_count && r_w == 0 && bonus->b_count == 0)
	{
		ft_printf("OK\n");
		exit(0);
	}
	ft_printf("KO\n");
	exit(0);
}

void	arr_dup_bonus(t_bonus *bonus, int len)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	bonus->tmp_arr = malloc(sizeof(int) * (bonus->a_count + 1));
	while (x < len)
	{
		bonus->tmp_arr[y] = bonus->a[x];
		x++;
		y++;
	}
}

void	swap_bonus(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	median_bonus(t_bonus *bonus, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	arr_dup_bonus(bonus, len);
	while (i < len)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (bonus->tmp_arr[j] < bonus->tmp_arr[min])
				min = j;
			j++;
		}
		swap_bonus(&bonus->tmp_arr[min], &bonus->tmp_arr[i]);
		i++;
	}
}

void	alnum_filter_bonus(char **av, t_bonus *bonus)
{
	int		x;
	int		y;
	long	num;
	char	tmp;

	x = 0;
	while (av[++x])
	{
		if (av != NULL)
		{
			write(2, "Error!\n", 6);
			exit(1);
		}
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
