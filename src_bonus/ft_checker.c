/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:07:36 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/22 11:13:52 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	ft_print(void *data)
// {
// 	int	*nb;

// 	nb = data;
// 	printf("%d\n", *nb);
// }
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

static void	free_bye(t_stack *a, t_stack *b, char *str)
{
	ft_freestacks(a, b);
	free(str);
	ft_print_error();
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
		free_bye(a, b, str);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (ac == 1)
		return (EXIT_FAILURE);
	a = ft_stack_create();
	b = ft_stack_create();
	ft_check_args(ac, av, a, b);
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		ft_do_operations(a, b, str);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (b->size == 0 && ft_is_sorted(a) == 1)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_stack_clear(a, free);
	ft_stack_clear(b, free);
}
