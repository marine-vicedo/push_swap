#include "push_swap.h"

t_list *ft_newNode(t_list *head, int value)
{
	t_list *newNode;
	
	newNode = malloc(sizeof(*newNode)); //equivaut a (sizeof(t_list)));
	
	if (newNode == NULL)
		return NULL;
		
	newNode->content = value;
	newNode->next = head;

	return (newNode);
}

t_list *ft_constructList(int *array, int size)
{
	t_list *head;
	int	i;

	head = NULL;
	i = size - 1;

	while (i >= 0)
	{
		head = ft_newNode(head, array[i]);
		i--;
	}
	return(head);
}

/*t_list *ft_lstlast(t_list *lst) //renvoie le dernier element de la liste
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

}*/
