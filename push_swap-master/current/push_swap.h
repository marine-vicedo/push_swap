#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct stack
{
    int value;
    struct stack *next;
} t_stack;

void    stack_add_back(t_stack **head, int value);
void    print_stack(t_stack *a);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	check_integers(char *str);
int	stack_size(t_stack *a);
void    swap(int *a, int *b);
void	swap_a(t_stack *a);
void	push_swap(t_stack *a, int size);

#endif