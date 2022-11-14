/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:11 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:47:54 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	numto_a_bonus(char **av, t_bonus *bonus)
{
	int		x;
	int		x_a;
	int		*num;

	x = 0;
	x_a = 0;
	num = malloc(sizeof(int) * (bonus->a_count + 1));
	bonus->b = malloc(sizeof(int) * (bonus->a_count + 1));
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
				exit(1);
			}
			y++;
		}
		x++;
	}
}

void	operator_check(char *opr)
{
	int	oppr_error;

	oppr_error = 1;
	if (!ft_strncmp("sa", opr, 4) || !ft_strncmp("sb", opr, 4))
		oppr_error = 0;
	else if (!ft_strncmp("pa", opr, 4) || !ft_strncmp("pb", opr, 4))
		oppr_error = 0;
	else if (!ft_strncmp("ra", opr, 4) || !ft_strncmp("rb", opr, 4))
		oppr_error = 0;
	else if (!ft_strncmp("rra", opr, 4))
		oppr_error = 0;
	else if (!ft_strncmp("rrb", opr, 4))
		oppr_error = 0;
	if (oppr_error == 1)
	{
		free(opr);
		write(1, "Invalid operator\n", 17);
		exit(1);
	}
}

void	get_oppr(t_bonus *bonus)
{
	char	*opr;
	char	*trimmed;

	opr = get_next_line(0);
	if (opr == NULL || opr[0] == '\n')
	{
		free(opr);
		return ;
	}
	trimmed = ft_strtrim(opr, "\n");
	free(opr);
	operator_check(trimmed);
	bonus_sort(trimmed, bonus);
	free(trimmed);
	get_oppr(bonus);
}

int	main(int ac, char **av)
{
	t_bonus	bonus;
	char	**tmp;
	char	**arr;
	int		y;
	int		x;

	if (ac == 1)
		exit(1);
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
	bonus.b_count = 0;
	alnum_filter_bonus(tmp, &bonus);
	numto_a_bonus(tmp, &bonus);
	dup_check_bonus(bonus.a, bonus.a_count);
	get_oppr(&bonus);
	bonus_check(&bonus, bonus.a_count);
}
