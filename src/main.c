/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:42:42 by khalid            #+#    #+#             */
/*   Updated: 2024/02/05 10:31:30 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print(void *data)
{
	int	*nb;

	nb = data;
	printf("%d\n", *nb);
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
	ft_lstiter(stack_a->top, ft_print);
	ft_rotate(stack_a);
	puts("ra");
	ft_lstiter(stack_a->top, ft_print);
	puts("ra");
	ft_rotate(stack_a);
	ft_lstiter(stack_a->top, ft_print);
		puts("ra");
	ft_rotate(stack_a);
	ft_lstiter(stack_a->top, ft_print);
}