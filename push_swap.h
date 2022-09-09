/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/09 18:42:45 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft_printf/libft.h"
# include "./libft_printf/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	a_count;
	int	b_count;
}	t_stack;

void	alt_f4(char *msg);
void	sa(t_stack *stack);

#endif