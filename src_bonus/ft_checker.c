/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:07:36 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/19 13:21:53 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_print(void *data)
{
	int	*nb;

	nb = data;
	printf("%d\n", *nb);
}

static void	ft_do_operations(t_stack *a, t_stack *b, char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		sa(a);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		sb(b);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ss(a, b);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		pa(b, a);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		pb(a, b);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		ra(a);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		rb(b);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		rra(a);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		rrb(b);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rrr(a, b);
	else
		ft_print_error();
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	if (ac == 1)
		return (EXIT_FAILURE);
	stack_a = ft_stack_create();
	stack_b = ft_stack_create();
	ft_check_args(ac, av, stack_a);
	ft_lstiter(stack_a->top, ft_print);
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		ft_do_operations(stack_a, stack_b, str);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (stack_b->size == 0 && ft_is_sorted(stack_a) == 1)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_stack_clear(stack_a, free);
	ft_stack_clear(stack_b, free);
}
