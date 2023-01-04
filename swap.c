/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:05:56 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 16:42:19 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *arr_a, char man_bon)
{
	int	tmp;

	tmp = arr_a[0];
	arr_a[0] = arr_a[1];
	arr_a[1] = tmp;
	if (man_bon == 'm')
		ft_printf("sa\n");
}

void	sb(int *arr_b, char man_bon)
{
	int	tmp;

	tmp = arr_b[0];
	arr_b[0] = arr_b[1];
	arr_b[1] = tmp;
	if (man_bon == 'm')
		ft_printf("sb\n");
}

void	ss(int *arr_a, int *arr_b)
{
	sa(arr_a, 'm');
	sb(arr_b, 'm');
}
