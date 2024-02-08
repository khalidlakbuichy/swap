/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:00:50 by khalid            #+#    #+#             */
/*   Updated: 2024/02/05 10:18:13 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	fake_free(void *data)
{
	if (data)
		return ;
	return ;
}

void	ft_swap(t_stack *stack)
{
	t_list	*head;
	t_list	*tmp;

	if (stack == NULL || ft_stack_is_empty(stack) || stack->top->next == NULL)
		return ;
	head = stack->top;
	tmp = head->next;
	tmp->prev = NULL;
	if (tmp->next != NULL)
		tmp->next->prev = head;
	head->next = tmp->next;
	tmp->next = head;
	head->prev = tmp;
	stack->top = tmp;
}

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || ft_stack_is_empty(stack_a))
		return ;
	ft_stack_push(stack_b, ft_stack_top(stack_a));
	ft_stack_pop(stack_a, fake_free);
}

void	ft_rotate(t_stack *stack)
{
	void	*data;

	if (stack == NULL || ft_stack_is_empty(stack))
		return ;
	data = ft_stack_top(stack);
	ft_stack_pop(stack, fake_free);
	if (ft_lstadd_back(&stack->top, ft_lstnew(data)))
		stack->size++;
}

void	ft_rrotate(t_stack *stack)
{
	t_list *tail;
	void *data;

	if (stack == NULL || ft_stack_is_empty(stack))
		return ;
	tail = stack->top;
	while (tail->next != NULL)
		tail = tail->next;
	data = tail->content;
	ft_lstdel_back(&stack->top, fake_free);
	ft_lstadd_front(&stack->top, ft_lstnew(data));
}
