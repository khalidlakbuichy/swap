/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/11 13:32:41 by klakbuic         ###   ########.fr       */
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
	int	*nbr;

	nbr = malloc(sizeof(int));
	if (nbr == NULL)
		return ;
	(*nbr) = nb;
	ft_stack_push(stack, nbr);
}

static int	ft_intcmp(void *a, void *b)
{
	int	*nb_a;
	int	*nb_b;

	nb_a = a;
	nb_b = b;
	if (*nb_a == *nb_b)
		return (0);
	return (1);
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
}
