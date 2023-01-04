/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwilliam <lwilliam@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:24:57 by lwilliam          #+#    #+#             */
/*   Updated: 2022/11/14 18:39:51 by lwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft_printf/libft.h"
# include "./libft_printf/ft_printf/ft_printf.h"
# include "./libft_printf/gnl/get_next_line.h"

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
	int	rb_count;
	int	ra_count;
	int	error;
}	t_stack;

typedef struct s_bonus
{
	int	*a;
	int	*b;
	int	*tmp_arr;
	int	a_count;
	int	b_count;
}	t_bonus;

void	alt_f4(int num);
void	pb(t_stack *stack);
void	move_a_up(t_stack *stack);
void	pa(t_stack *stack);
void	move_b_up(t_stack *stack);
void	dup_check(int *where, int where_len);
int		first_two(t_stack *stack);
void	num_check(char **av, t_stack *stack, int ac);
void	check(char **av, t_stack *stack, int len, int ac);
void	t_num_a(t_stack *stack, int tmp);
void	t_num_b(t_stack *stack);
void	two_num(t_stack *stack, char a_b);
void	last(t_stack *stack);
void	arr_dup(t_stack *stack, char a_b);
void	median(t_stack *stack, char a_b, char num, int len);
void	med(t_stack *stack);
void	pushing(t_stack *stack, char a_b);
void	rotate(t_stack *stack, char a_b, int x);
void	quick_sort_a(char **av, t_stack *stack, int len);
void	quick_sort_b(char **av, t_stack *stack, int len);
void	free_funct(char **av);
void	median_utils(t_stack *stack, int len);
void	push_b_util(t_stack *stack);
void	init_funct(t_stack *stack);

void	sa(int *arr_a, char man_bon);
void	sb(int *arr_b, char man_bon);
void	ss(int *arr_a, int *arr_b);
void	ra(int *arr_a, int a_count, char man_bon);
void	rb(int *arr_b, int b_count, char man_bon);
void	rr(int *arr_a, int *arr_b, int a_count, int b_count);
void	rra(int *arr_a, int a_count, char man_bon);
void	rrb(int	*arr_b, int b_count, char man_bon);
void	rrr(int *arr_a, int *arr_b, int a_count, int b_count);

void	pb_bonus(t_bonus *bonus);
void	move_a_up_bonus(t_bonus *bonus);
void	pa_bonus(t_bonus *bonus);
void	move_b_up_bonus(t_bonus *bonus);

void	alnum_filter_bonus(char **av, t_bonus *bonus);
void	numto_a_bonus(char **av, t_bonus *bonus);
void	dup_check_bonus(int *where, int where_len);
void	get_oppr(t_bonus *bonus);
void	bonus_sort(char *opr, t_bonus *bonus);
void	median_bonus(t_bonus *bonus, int len);
void	bonus_check(t_bonus *bonus, int len);
// void	print_test(t_stack *stack, char *where_a, char *where_b);

#endif