/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:59 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:12:06 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_bonus(t_bonus *bonus)
{
	int	tmp;

	if (bonus->b_count == 0)
	{
		bonus->b[0] = bonus->a[0];
		bonus->b_count += 1;
		move_a_up_bonus(bonus);
	}
	else
	{
		tmp = bonus->b_count;
		while (tmp >= 0)
		{
			bonus->b[tmp + 1] = bonus->b[tmp];
			tmp--;
		}
		bonus->b_count += 1;
		bonus->b[0] = bonus->a[0];
		move_a_up_bonus(bonus);
	}
}

void	move_a_up_bonus(t_bonus *bonus)
{
	int	tmp;

	tmp = 0;
	bonus->a_count -= 1;
	while (tmp < bonus->a_count)
	{
		bonus->a[tmp] = bonus->a[tmp + 1];
		tmp++;
	}
}

void	pa_bonus(t_bonus *bonus)
{
	int	tmp;

	if (bonus->a_count == 0)
	{
		bonus->a[0] = bonus->b[0];
		bonus->a_count += 1;
		move_b_up_bonus(bonus);
	}
	else
	{
		tmp = bonus->a_count;
		while (tmp >= 0)
		{
			bonus->a[tmp + 1] = bonus->a[tmp];
			tmp--;
		}
		bonus->a_count += 1;
		bonus->a[0] = bonus->b[0];
		move_b_up_bonus(bonus);
	}
}

void	move_b_up_bonus(t_bonus *bonus)
{
	int	tmp;

	tmp = 0;
	bonus->b_count -= 1;
	while (tmp < bonus->b_count)
	{
		bonus->b[tmp] = bonus->b[tmp + 1];
		tmp++;
	}
}

void	bonus_sort(char *opr, t_bonus *bonus)
{
	if (!ft_strncmp("sa", opr, 4))
		sa(bonus->a, 'b');
	if (!ft_strncmp("sb", opr, 4))
		sb(bonus->b, 'b');
	if (!ft_strncmp("ra", opr, 4))
		ra(bonus->a, bonus->a_count, 'b');
	if (!ft_strncmp("rb", opr, 4))
		rb(bonus->b, bonus->b_count, 'b');
	if (!ft_strncmp("rra", opr, 4))
		rra(bonus->a, bonus->a_count, 'b');
	if (!ft_strncmp("rrb", opr, 4))
		rrb(bonus->b, bonus->b_count, 'b');
	if (!ft_strncmp("pa", opr, 4))
		pa_bonus(bonus);
	if (!ft_strncmp("pb", opr, 4))
		pb_bonus(bonus);
}
