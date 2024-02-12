/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/12 12:44:58 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_print_error(void)
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

void ft_make_table(t_stack *a)
{
	t_element *elm;
	t_list *head = a->top;
	
	int *tab = (int *) malloc(sizeof(int) * (a->size + 1));
	for (int i = 0; (i < a->size) && head != NULL; i++)
	{
		elm = head->content;
		tab[i] = elm->nb;
		head = head->next;
	}
	for (int i = 0; (i < a->size); i++)
	{
		printf("i: %d\n", tab[i]);
	}
}

void	ft_check_args(int ac, char **av, t_stack *stack_a)
{
	int		nb;
	int		i;
	int		j;
	int		error;
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
			nb = ft_atoi_enhanced(av[i], &error);
			if (ft_lstsearh_item(stack_a->top, &nb, ft_intcmp))
				ft_print_error();
			push_nb_to_stack(stack_a, nb);
			if (error)
				ft_print_error();
		}
		while (splited_av[j] != NULL)
		{
			push_nb_to_stack(stack_a, ft_atoi_enhanced(splited_av[j], &error));
			if (error)
				ft_print_error();
			j++;
		}
		i++;
	}
	ft_make_table(stack_a);
}
