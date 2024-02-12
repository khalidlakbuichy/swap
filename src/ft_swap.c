/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:04:37 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/11 13:32:15 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(t_stack *stack)
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

void	sa(t_stack *a)
{
	ft_swap(a);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *b)
{
	ft_swap(b);
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putendl_fd("ss", STDOUT_FILENO);
}