#include "push_swap.h"

t_list *ft_lstnew(void *content)
{
	t_list *element;
	
	element = malloc(sizeof(*element)); //equivaut a (sizeof(t_list)));
	
	if (element == NULL)
		return NULL;
		
	element->content = content;
	element->next = NULL;

	return (element);
}

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return NULL;
	while (lst->next != NULL)
		lst = lst->next; // le pointeur se deplace jusqu'a next = NULL
	return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	if (lst == NULL || new == NULL) // si les pointeurs ne pointent sur rien
		exit(EXIT_FAILURE);
	if (*lst) // si la liste a un premier element = si le debut de la liste n'est pas nulle
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_list_init(char **args)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 0;
	a = ft_lstnew(args[i++]);
	while (args[i] != NULL)
		ft_lstadd_back(&a, ft_lstnew(args[i++]));
	return (a);
}

void ft_clearlst(t_list **lst)
{
	t_list	*tmp;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}

}
