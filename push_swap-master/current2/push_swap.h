#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct stack
{
    int value;
    struct stack *next;
    int index;
} t_stack;

void    stack_add_back(t_stack **head, int value);
void    print_stack(t_stack *stack);
void    free_stack(t_stack **head);
long int	    ft_atoi(const char *str);
int	    check_for_numbers(const char *str);
int	    ft_isdigit(int c);
int	    ft_stack_size(t_stack *stack);
void    swap(int *a, int *b);
void	swap_nodes(t_stack **stack);
void	push_swap(t_stack **a, int stack_size);
int	    check_sort(t_stack **a);
int     check_input(char **argv);
t_stack	*init_stack_a(char **argv, t_stack *a);
void    push_b(t_stack **a, t_stack **b);
void    rotate(t_stack **head);
void    reverse_rotate(t_stack **head);
int     ft_compare(char *s1, char *s2);
int	    check_duplicates(t_stack *a);
void	exit_error(t_stack **a);
void	get_index(t_stack **copy, t_stack **a, int stack_size);
t_stack	*ft_stack_copy(t_stack *a);
void	algo_for_3(t_stack **a);

#endif