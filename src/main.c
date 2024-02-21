/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:42:42 by khalid            #+#    #+#             */
/*   Updated: 2024/02/21 13:44:25 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	ft_freestacks(t_stack *a, t_stack *b)
{
	bool	feedback;

	feedback = ft_stack_clear(a, free);
	feedback = ft_stack_clear(b, free);
	return (feedback);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	a = ft_stack_create();
	b = ft_stack_create();
	ft_check_args(ac, av, a, b);
	if (ft_is_sorted(a))
	{
		ft_freestacks(a, b);
		return (EXIT_SUCCESS);
	}
	ft_sort_stack(a, b);
	ft_stack_clear(a, free);
	ft_stack_clear(b, free);
}
