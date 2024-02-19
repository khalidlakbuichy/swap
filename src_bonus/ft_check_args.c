/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/19 11:23:17 by klakbuic         ###   ########.fr       */
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
		{
			nb = ft_atoi_enhanced(splited_av[j++]);
			if (ft_lstsearh_item(stack_a->top, &nb, ft_intcmp))
				ft_print_error();
			push_nb_to_stack(stack_a, nb);
		}
		split_free(splited_av);
		i++;
	}
}
