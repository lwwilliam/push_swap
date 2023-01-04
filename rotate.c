/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:22:15 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 16:38:49 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *arr_a, int a_count, char man_bon)
{
	int	tmp;
	int	first;

	tmp = 0;
	first = arr_a[0];
	while (tmp < a_count - 1)
	{
		arr_a[tmp] = arr_a[tmp + 1];
		tmp++;
	}
	arr_a[tmp] = first;
	if (man_bon == 'm')
		ft_printf("ra\n");
}

void	rb(int *arr_b, int b_count, char man_bon)
{
	int	tmp;
	int	first;

	tmp = 0;
	first = arr_b[0];
	while (tmp < b_count - 1)
	{
		arr_b[tmp] = arr_b[tmp + 1];
		tmp++;
	}
	arr_b[tmp] = first;
	if (man_bon == 'm')
		ft_printf("rb\n");
}

void	rr(int *arr_a, int *arr_b, int a_count, int b_count)
{
	ra(arr_a, a_count, 'm');
	rb(arr_b, b_count, 'm');
}
