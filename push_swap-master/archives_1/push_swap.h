#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int		content;
	struct node	*next;
}	t_list;

void ft_clearlst(t_list **lst);
//t_list	*ft_list_init(int *args);
//void ft_lstadd_back(t_list **lst, t_list *new);
//t_list *ft_lstlast(t_list *lst);
//t_list *ft_lstnew(int value);
int	ft_atoi(const char *str);
t_list *ft_newNode(t_list *head, int value);
t_list *ft_constructList(int array[i], int size);
void	ft_printList(t_list *head);

#endif