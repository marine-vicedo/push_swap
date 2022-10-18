/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:05:13 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/11 19:08:02 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
void			print_stack(t_stack *stack);
void			free_stack(t_stack **stack);

/* --------------------- parsing --------------------- */
int				check_for_numbers(const char *str);
int				check_input(char **argv);
int				check_duplicates(t_stack *a);
void			exit_error(t_stack **a, t_stack **b);

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

/* --------------------- sort ---------------------- */
int				check_sort(t_stack **a);

/* --------------------- utils ---------------------- */
long int		ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);

/* --------------------- checker ---------------------- */
char			*read_instructions(int fd);
char			*ft_strjoin(char *stash, char *buffer);
char			**tab_instructions(char *str);
void			sort_stack(char **moves, t_stack **a, t_stack **b);
void			do_instructions(char *move, t_stack **a, t_stack **b,
					char **moves);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
char			**ft_split(char const *s, char sep);
void			free_tab(char **tab);
void			free_all(t_stack **a, t_stack **b, char **moves);
void			error_instruction(t_stack **a, t_stack **b, char **moves);

#endif