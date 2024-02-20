/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:42:42 by khalid            #+#    #+#             */
/*   Updated: 2024/02/20 15:11:02 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
void ft_print(void *data)
{
	int *nb;

	nb = data;
	printf("%d\n", *nb);
}
void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	ft_freestacks(t_stack *stack_a, t_stack *stack_b)
{
	bool feedback;
	feedback = ft_stack_clear(stack_a, free);
	feedback = ft_stack_clear(stack_b, free);
	return (feedback);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		ft_print_error();
	stack_a = ft_stack_create();
	stack_b = ft_stack_create();
	ft_check_args(ac, av, stack_a, stack_b);
	if (ft_is_sorted(stack_a))
	{
		ft_freestacks(stack_a, stack_b);
		return (EXIT_SUCCESS);
	}
	ft_sort_stack(stack_a, stack_b);
	// ft_lstiter(stack_a->top, ft_print);
	ft_stack_clear(stack_a, free);
	ft_stack_clear(stack_b, free);
}
