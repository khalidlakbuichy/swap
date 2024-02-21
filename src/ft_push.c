/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:15:02 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/21 13:39:23 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fake_free(void *data)
{
	if (data)
		return ;
	return ;
}

static void	ft_push(t_stack *a, t_stack *b)
{
	if (a == NULL || b == NULL || ft_stack_is_empty(a))
		return ;
	ft_stack_push(b, ft_stack_top(a));
	ft_stack_pop(a, fake_free);
}

void	pa(t_stack *b, t_stack *a)
{
	ft_push(b, a);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_putendl_fd("pb", STDOUT_FILENO);
}
