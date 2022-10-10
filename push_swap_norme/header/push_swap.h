/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:57:02 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/10 17:14:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
}	t_stack;

/* --------------------- init stack -------------------- */
t_stack			*init_stack_a(char **argv, t_stack *a);
void			stack_add_back(t_stack **stack, int value);
int				ft_stack_size(t_stack *stack);
void			print_stack(t_stack *stack);
void			free_stack(t_stack **stack);

/* --------------------- parsing --------------------- */
int				check_for_numbers(const char *str);
int				check_input(char **argv);
int				check_duplicates(t_stack *a);
void			exit_error(t_stack **a, t_stack **b);

/* --------------------- algos ---------------------- */
void			push_swap(t_stack **a, t_stack **b, int stack_size);
int				check_sort(t_stack **a);
void			algo_for_3(t_stack **a);
void			big_sort(t_stack **a, t_stack **b, int stack_size_a);
void			push_all_in_b(t_stack **a, t_stack **b, int stack_size_a);
void			last_sort_for_a(t_stack **a, int stack_size_a);

/* --------------------- moves ---------------------- */
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			pa(t_stack **b, t_stack **a);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rotate_both(t_stack **a, t_stack **b);
void			reverse_rotate_both(t_stack **a, t_stack **b);

/* --------------------- index ---------------------- */
void			get_index(t_stack *a);
int				get_index_max(t_stack *stack);

/* --------------------- positions ---------------------- */
void			get_position(t_stack **stack);
int				get_position_index_min(t_stack **a);
void			target_position_for_b(t_stack **a, t_stack **b);
int				define_target_stack_a(t_stack **a, int index_b,
					int index_target, int target_pos_b);

/* --------------------- costs & moves ---------------------- */
void			cost(t_stack **a, t_stack **b);
void			find_the_better_move(t_stack **a, t_stack **b);
void			stack_rotations(t_stack **a, t_stack **b,
					int cost_a, int cost_b);

/* --------------------- utils ---------------------- */
long int		ft_atoi(const char *str);
int				abs_nbr(int nbr);
void			ft_putstr_fd(char *s, int fd);

#endif
