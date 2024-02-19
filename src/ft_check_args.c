/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/19 10:20:46 by klakbuic         ###   ########.fr       */
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
	ft_stack_rpush(stack_a, nbr);
}

int	ft_intcmp(void *ref, void *data)
{
	int	*nb_a;
	int	*nb_b;

	nb_a = ref;
	nb_b = data;
	if (*nb_a > *nb_b)
		return (1);
	else if (*nb_a < *nb_b)
		return (-1);
	else
		return (0);
}

static void	ft_change_stack(t_stack *stack_a, int *arr)
{
	int		i;
	int		*nb;
	t_list	*head;

	i = 0;
	head = stack_a->top;
	while ((head != NULL) && (i < stack_a->size))
	{
		if (ft_intcmp(head->content, (arr + i)) == 0)
		{
			nb = head->content;
			*nb = (i + 1);
			head = head->next;
			i = -1;
		}
		i++;
	}
	free(arr);
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

static void	split_free(char **splited_str)
{
	int	i;

	i = -1;
	if (splited_str == NULL)
		return ;
	while (splited_str[++i] != NULL)
		free(splited_str[i]);
	free(splited_str);
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
		split_free(splited_av);
		i++;
	}
	ft_make_table(stack_a);
}
