#include "push_swap.h"

	/* PSEUDO CODE
	if (check_integers(argv) = 1 || check_duplicate(argv) = 1
		|| check_int_max(argv) = 1)
		fprintf(stderr, "Error\n"); */


int	main (int argc, char **argv)
{
	t_list	*a;

	a = NULL;
	if (argc < 2)
		return 0;
	a = ft_list_init(&argv[1]);
	while (a != NULL)
	{
		printf("%s -> ", (char *)(a->content));
		if (a->next == NULL)
			break;
		a = a->next;
	}
	printf("NULL\n");
	ft_clearlst(&a);
	if (a == NULL)
		printf("la liste est vide\n");
}


	/*
	int	i;
	int j;
	int size;
	int	tab[10];

	i = 1;
	j = 1;
	while (i < argc)
		i++;
	size = i - 1;
	//printf("%d\n", size);
	while (j <= size)// copy to tab
		{
			tab[j] = atoi(argv[j]);
			printf("%d\n", tab[j]);
			j++;
		}
		*/