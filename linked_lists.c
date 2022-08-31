#include "push_swap.h"

t_list *ft_lstnew(int value)
{
	t_list *newElement;
	
	newElement = malloc(sizeof(*newElement)); //equivaut a (sizeof(t_list)));
	
	if (newElement == NULL)
		return NULL;
		
	newElement->content = value;
	newElement->next = NULL;

	return (newElement);
}

t_list *ft_lstlast(t_list *lst) //renvoie le dernier element de la liste
{
	if (lst == NULL)
		return NULL;
	while (lst->next != NULL)
		lst = lst->next; // le pointeur se deplace jusqu'a next = NULL
	return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new) //ajoute element 'new' a la fin de la liste
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

t_list	*ft_list_init(int *args)
{
	t_list	*a;
	int		i;

	a = NULL;
	i = 1;
	printf("%d\n", args[i]);
	a = ft_lstnew(args[i++]);
	printf("%d\n", args[i]);
	while (args[i])
	{
		ft_lstadd_back(&a, ft_lstnew(args[i++]));
		printf("%d\n", args[i]);
	}
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
