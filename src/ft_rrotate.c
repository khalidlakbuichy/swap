/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:18:53 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/19 13:25:48 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fake_free(void *data)
{
	if (data)
		return ;
	return ;
}

static void	ft_rrotate(t_stack *stack)
{
	t_list	*tail;
	void	*data;

	if (stack == NULL || ft_stack_is_empty(stack))
		return ;
	tail = stack->top;
	while (tail->next != NULL)
		tail = tail->next;
	data = tail->content;
	ft_lstdel_back(&stack->top, fake_free);
	ft_lstadd_front(&stack->top, ft_lstnew(data));
}

void	rra(t_stack *a)
{
	ft_rrotate(a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_stack *b)
{
	ft_rrotate(b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
