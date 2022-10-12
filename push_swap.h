/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/10/12 16:57:02 by lwilliam         ###   ########.fr       */
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
	int	run_num;
	int	run_set;
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
void	dup_check(t_stack *stack);
int		first_two(t_stack *stack);
void	num_check(char **av, t_stack *stack);
void	num_check2(char **av, t_stack *stack);
void	check(t_stack *stack);
void	t_num_a(t_stack *stack);
void	two_num(t_stack *stack, char a_b);
void	arr_dup(t_stack *stack, char a_b);
void	sort(t_stack *stack, char a_b, char num);
void	med(t_stack *stack, char a_b);
void	pushing(t_stack *stack, char a_b);

void	print_test(t_stack *stack, char *where_a, char *where_b);

#endif