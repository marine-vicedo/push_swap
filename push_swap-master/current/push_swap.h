#include <stdio.h>
#include <stdlib.h>

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
void    ft_clearstack(t_stack **head);
int	    ft_atoi(const char *str);
int	    ft_isdigit(int c);
int	    check_integers(char *str);
int	    ft_stack_size(t_stack *stack);
void    swap(int *a, int *b);
void	swap_nodes(t_stack *stack);
void	push_swap(t_stack *a, t_stack *b, int stack_size);
int	    ft_is_sorted(t_stack *a);
int     check_input(char **argv);
t_stack	*fill_stack_args(int argc, char **argv, t_stack *a);
void    push_b(t_stack **a, t_stack **b);
void    rotate(t_stack **head);
void    reverse_rotate(t_stack **head);


#endif