/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:42:42 by khalid            #+#    #+#             */
/*   Updated: 2024/02/15 10:48:43 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_print(void *data)
{
	int	*nbr;

	nbr = data;
	printf("%d\n", *nbr);
}

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (ac == 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	stack_a = ft_stack_create();
	stack_b = ft_stack_create();
	ft_check_args(ac, av, stack_a);
	// ft_lstiter(stack_a->top, ft_print);
	ft_sort_stack(stack_a, stack_b, 4);
	// ft_lstiter(stack_b->top, ft_print);
	// rrb(stack_b);
	// rrb(stack_b);
	// ft_lstiter(stack_b->top, ft_print);
	// puts("------------------------------- stack a: ----------------------");
	// printf("stack_a size: %d\n", stack_a->size);
	// ra(stack_a);
	// ra(stack_a);
	// ra(stack_a);
	// printf("stack: %d\n", stack_a->size);
	// puts("---------------------------------------------------------------");
	// puts("------------------------------- stack a: ----------------------");
	// ft_stack_pop(stack_a, free);
	// ft_stack_pop(stack_a, free);
	// ft_stack_pop(stack_a, free);
	// printf("stack_a size: %d\n", stack_a->size);
	// ft_lstiter(stack_a->top, ft_print);
	// puts("---------------------------------------------------------------");
	// printf("is sorted: %d\n", ft_is_sorted(stack_a));
}