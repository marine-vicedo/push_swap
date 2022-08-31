#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct element
{
	int		content;
	struct element	*next;
}	t_list;

void ft_clearlst(t_list **lst);
t_list	*ft_list_init(int *args);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstnew(int value);
int	ft_atoi(const char *str);
void	tableau(int argc, char **argv);

#endif