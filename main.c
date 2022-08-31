#include "push_swap.h"

	/* PSEUDO CODE
	if (check_integers(argv) = 1 || check_duplicate(argv) = 1
		|| check_int_max(argv) = 1)
		fprintf(stderr, "Error\n"); */


int	main (int argc, char **argv)
{
	t_list	*a;
	int		*tab;
	int	i;
	int j;
	int size;

	i = 1;
	j = 1;
	if (argc < 2)
		return 0;
	while (i < argc)
		i++;
	size = i - 1;
	tab = malloc(size*sizeof(int));
	if (!tab)
		return 0;
	while (j <= size)// copy to tab
	{
		tab[j] = ft_atoi(argv[j]);
		//printf("%d\n", tab[j]);
		j++;
	}
	a = NULL;
	a = ft_list_init(tab);
	while (a != NULL)
	{
		printf("%d -> ", (a->content));
		if (a->next == NULL)
			break;
		a = a->next;
	}
	printf("NULL\n");
	ft_clearlst(&a);
	if (a == NULL)
		printf("la liste est vide\n");
}


