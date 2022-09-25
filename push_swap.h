/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/09/26 01:05:45 by lwilliam         ###   ########.fr       */
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
	int	*tmp_arr;
	int	median;
	int	arr_count;
	int	med_pos;
	int fst_run;
	int	tmp_arr_count;

}	t_stack;

void	alt_f4(char *msg);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	move_a_up(t_stack *stack);
void	pa(t_stack *stack);
void	move_b_up(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	t_num_a(t_stack *stack);
void	two_num(t_stack *stack, char a_b);
void	arr_dup(t_stack *stack, char a_b);
void	sort(t_stack *stack, char a_b);
void	med(t_stack *stack, char a_b);
void	pushing(t_stack *stack, char a_b);
// void	pushing2(t_stack *stack, char a_b);


void	print_test(t_stack *stack, char *where_a, char *where_b);

#endif