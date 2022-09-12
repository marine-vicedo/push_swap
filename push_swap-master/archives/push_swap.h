#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int		content;
	struct node	*next;
}	node;

typedef struct stack
{
	node	*first;
} t_stack;

t_stack	*ft_stack_init();
void ft_add_back(t_stack *stack, int value);
void ft_print_stack(t_stack *stack);
int	ft_atoi(const char *str);
int	check_integers(char *argv);

#endif