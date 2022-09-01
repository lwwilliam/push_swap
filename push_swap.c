/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:04 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/01 18:33:48 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alnum_filter(char **av)
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
		{
			ft_printf("Some arguments contains invalid integer!\n");
			exit(0);
		}
		y = 0;
		while (av[x][y])
		{
			tmp = av[x][y++];
			if (ft_isalpha(tmp) == 1)
			{
				ft_printf("Some arguments aren't integer!\n");
				exit(0);
			}
		}
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_printf("Arguments is less than 2\n");
	alnum_filter(av);
}
