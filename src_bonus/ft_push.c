/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:15:02 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/19 11:32:30 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fake_free(void *data)
{
	if (data)
		return ;
	return ;
}

static void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || ft_stack_is_empty(stack_a))
		return ;
	ft_stack_push(stack_b, ft_stack_top(stack_a));
	ft_stack_pop(stack_a, fake_free);
}

void pa(t_stack *b, t_stack *a)
{
    ft_push(b, a);
}

void pb(t_stack *a, t_stack *b)
{
    ft_push(a, b);
}