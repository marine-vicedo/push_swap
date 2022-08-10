#include <stdio.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

void ft_clearlst(t_list **lst);
t_list	*ft_list_init(char **args);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstnew(void *content);

#endif