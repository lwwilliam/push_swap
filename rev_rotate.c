/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:39:51 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 16:32:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *arr_a, int a_count, char man_bon)
{
	int	tmp;
	int	last;

	last = arr_a[a_count - 1];
	tmp = a_count - 1;
	while (tmp > -1)
	{
		arr_a[tmp + 1] = arr_a[tmp];
		tmp--;
	}
	arr_a[0] = last;
	if (man_bon == 'm')
		ft_printf("rra\n");
}

void	rrb(int	*arr_b, int b_count, char man_bon)
{
	int	tmp;
	int	last;

	last = arr_b[b_count - 1];
	tmp = b_count - 1;
	while (tmp > -1)
	{
		arr_b[tmp + 1] = arr_b[tmp];
		tmp--;
	}
	arr_b[0] = last;
	if (man_bon == 'm')
		ft_printf("rrb\n");
}

void	rrr(int *arr_a, int *arr_b, int a_count, int b_count)
{
	rra(arr_a, a_count, 'm');
	rrb(arr_b, b_count, 'm');
}
