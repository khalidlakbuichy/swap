/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/14 10:08:19 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	push_nb_to_stack(t_stack *stack_a, int nb)
{
	int	*nbr;

	nbr = (int *)malloc(sizeof(int));
	if (nbr == NULL)
	{
		/* Do some error handling */
	}
	*nbr = nb;
	// printf("nb: %d\n", *nbr);
	ft_stack_push(stack_a, nbr);
}

int	ft_intcmp(void *ref, void *data)
{
	int	*nb_a;
	int	*nb_b;

	nb_a = ref;
	nb_b = data;
	printf("nb_a: %d\n", *nb_a);
	printf("nb_b: %d\n", *nb_b);
	if (*nb_a > *nb_b)
	{
		puts("sup");
		return (1);
	}
	else if (*nb_a < *nb_b)
	{
		puts("inf");
		return (-1);
	}
	else
	{
		puts("zero");
		return (0);
	}
}

// static void	ft_print(void *data)
// {
// 	int	*nbr;

// 	nbr = data;
// 	printf("nb: %d\n", *nbr);
// }

static void	ft_change_stack(t_stack *stack_a, int *arr)
{
	int		i;
	int		*nb;
	t_list	*head;
	void	*stack_item;

	i = 0;
	head = stack_a->top;
	while ((head != NULL) && (i < stack_a->size))
	{
		stack_item = ft_lstsearh_item(stack_a->top, (arr + i), ft_intcmp);
		if (stack_item != NULL)
		{
			nb = stack_item;
			*nb = (i + 1);
		}
		head = head->next;
		i++;
	}
}

static void	ft_make_table(t_stack *stack_a)
{
	t_list	*head;
	int		*arr;
	int		i;
	int		*tmp;

	head = stack_a->top;
	arr = (int *)malloc(sizeof(int) * (stack_a->size));
	if (arr == NULL)
	{
		/* some error handling ;) */
	}
	i = 0;
	while (head != NULL && (i < stack_a->size))
	{
		tmp = head->content;
		arr[i++] = *tmp;
		head = head->next;
	}
	ft_qsort(arr, stack_a->size);
	ft_change_stack(stack_a, arr);
}

void	ft_check_args(int ac, char **av, t_stack *stack_a)
{
	int		nb;
	int		i;
	int		j;
	char	**splited_av;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_print_error();
		splited_av = ft_split(av[i], ' ');
		j = 0;
		if (splited_av[j] == NULL)
		{
			nb = ft_atoi_enhanced(av[i]);
			if (ft_lstsearh_item(stack_a->top, &nb, ft_intcmp))
				ft_print_error();
			push_nb_to_stack(stack_a, nb);
		}
		while (splited_av[j] != NULL)
			push_nb_to_stack(stack_a, ft_atoi_enhanced(splited_av[j++]));
		/* Don't forget the memor leaks ;)*/
		i++;
	}
	ft_make_table(stack_a);
}
