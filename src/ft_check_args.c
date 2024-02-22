/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/22 09:48:30 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static void	push_nb_to_stack(t_stack *a, t_stack *b, char **sp, int nb)
{
	int	*nbr;

	if (ft_lstsearh_item(a->top, &nb, cmp))
	{
		ft_freestacks(a, b);
		split_free(sp);
		ft_print_error();
	}
	nbr = (int *)malloc(sizeof(int));
	if (nbr == NULL)
		return ;
	*nbr = nb;
	ft_stack_rpush(a, nbr);
}

static void	ft_change_stack(t_stack *a, int *arr)
{
	int		i;
	int		*nb;
	t_list	*head;

	i = 0;
	head = a->top;
	while ((head != NULL) && (i < a->size))
	{
		if (cmp(head->content, (arr + i)) == 0)
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

static void	ft_make_table(t_stack *a)
{
	t_list	*head;
	int		*arr;
	int		i;
	int		*tmp;

	head = a->top;
	arr = (int *)malloc(sizeof(int) * (a->size));
	if (arr == NULL)
	{
		ft_stack_clear(a, free);
		ft_putendl_fd("Memory allocation failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (head != NULL && (i < a->size))
	{
		tmp = head->content;
		arr[i++] = *tmp;
		head = head->next;
	}
	ft_qsort(arr, a->size);
	ft_change_stack(a, arr);
}

void	ft_check_args(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		flag;
	char	**sp;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '\0')
			ft_print_error();
		sp = ft_split(av[i], ' ');
		j = 0;
		if (sp[j] == NULL)
			push_nb_to_stack(a, b, sp, ft_atoi_enhanced(av[i], &flag));
		while (sp[j] != NULL)
			push_nb_to_stack(a, b, sp, ft_atoi_enhanced(sp[j++], &flag));
		split_free(sp);
		if (flag == 1 && ft_freestacks(a, b))
			ft_print_error();
	}
	ft_make_table(a);
}
