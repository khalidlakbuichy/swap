/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:42:42 by khalid            #+#    #+#             */
/*   Updated: 2024/02/14 13:09:11 by klakbuic         ###   ########.fr       */
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
	// ft_sort_stack(stack_a, stack_b, 4);
	puts("------------------------------- stack a: ----------------------");
	printf("stack_a size: %d\n", stack_a->size);
	ft_lstiter(stack_a->top, ft_print);
	puts("---------------------------------------------------------------");
	puts("------------------------------- stack a: ----------------------");
	printf("stack_a size: %d\n", stack_a->size);
	printf("pop :%d\n", ft_stack_pop(stack_a, free));
	ft_lstiter(stack_a->top, ft_print);
	puts("---------------------------------------------------------------");
	// printf("is sorted: %d\n", ft_is_sorted(stack_a));
}