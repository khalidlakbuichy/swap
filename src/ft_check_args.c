/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/12 15:14:26 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	push_nb_to_stack(t_stack *stack, int nb)
{
	static unsigned int	index;
	t_element			*elm;

	elm = malloc(sizeof(t_element));
	if (elm == NULL)
		return ;
	elm->nb = nb;
	elm->index = index++;
	ft_stack_push(stack, elm);
}

static int	ft_intcmp(void *ref, void *data)
{
	int			*nb;
	t_element	*elm;

	nb = ref;
	elm = data;
	// printf("nb 		: %d\n", *nb);
	// printf("element : %d\n", elm->nb);
	if (*nb == elm->nb)
		return (0);
	return (1);
}
void	ft_print(void *data)
{
	t_element	*elm;

	elm = data;
	printf("nb: %d\n", elm->nb);
}

void	ft_change_stack(t_stack *a, int *arr)
{
	int			i;
	t_element	*elm;
	t_list		*head;

	i = 0;
	head = a->top;
	while (i < a->size)
	{
		if (ft_lstsearh_item(a->top, (arr + i), ft_intcmp) == 0)
		{
			elm = head->content;
			elm->nb = i;
			i++;
		}
		head = head->next;
	}
	ft_lstiter(a->top, ft_print);
}

void	ft_make_table(t_stack *a)
{
	// int			i;
	t_element	*elm;
	t_list		*head;
	int			*tab;

	head = a->top;
	tab = (int *)malloc(sizeof(int) * (a->size));
	for (int i = 0; (i < a->size) && head != NULL; i++)
	{
		elm = head->content;
		tab[i] = elm->nb;
		head = head->next;
	}
	ft_qsort(tab, a->size);
	ft_change_stack(a, tab);
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
				ft_error();
			push_nb_to_stack(stack_a, nb);
		}
		while (splited_av[j] != NULL)
			push_nb_to_stack(stack_a, ft_atoi_enhanced(splited_av[j++]));
		i++;
	}
	ft_make_table(stack_a);
}
