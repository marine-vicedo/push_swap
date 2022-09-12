#include "push_swap.h"

	/* PSEUDO CODE
	if (check_integers(argv) = 1 || check_duplicate(argv) = 1
		|| check_int_max(argv) = 1)
		fprintf(stderr, "Error\n"); */

void	ft_printList(t_list *head)
{
	while (head != NULL)
	{
		printf("%d -> ", (head->content));
		/*if (ptr->next == NULL)
			break;*/
		head = head->next;
	}
}

int	main (int argc, char **argv)
{
	t_list	*head;
	int		array[100];
	int	i;
	int j;
	int size;

	i = 1;
	j = 1;
	if (argc == 1)
		return 0;
	//array = malloc(size*sizeof(int));
	//if (!array)
	//	free (array);
	size = sizeof(array)/sizeof(array[0]);
	while (j <= size)
	{
		array[j] = ft_atoi(argv[j]);
		//printf("%d\n", tab[j]);
		j++;
	}
	head = ft_constructList(array, size);
	ft_printList(head);
	printf("NULL\n");
	/*ft_clearlst(&a);
	if (a == NULL)
		printf("la liste est vide\n");*/
}


