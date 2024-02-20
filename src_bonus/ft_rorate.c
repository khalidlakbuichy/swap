/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rorate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:10:37 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/19 13:23:11 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fake_free(void *data)
{
	if (data)
		return ;
	return ;
}

static void	ft_rotate(t_stack *stack)
{
	void	*data;

	if (stack == NULL || ft_stack_is_empty(stack))
		return ;
	data = ft_stack_top(stack);
	ft_stack_pop(stack, fake_free);
	if (ft_lstadd_back(&stack->top, ft_lstnew(data)))
		stack->size++;
}

void	ra(t_stack *a)
{
	ft_rotate(a);
}

void	rb(t_stack *b)
{
	ft_rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}
