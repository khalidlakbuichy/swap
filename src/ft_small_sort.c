/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:23:51 by khalid            #+#    #+#             */
/*   Updated: 2024/02/19 13:25:52 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	*get_max(t_stack *stack_a)
{
	t_list	*head;
	void	*max;

	head = stack_a->top;
	max = head->content;
	while (head != NULL)
	{
		if (ft_intcmp(head->content, max) > 0)
			max = head->content;
		head = head->next;
	}
	return (max);
}

void	ft_small_sort(t_stack *stack_a)
{
	void *max;

	max = get_max(stack_a);
	if (ft_intcmp(stack_a->top->content, max) == 0)
		ra(stack_a);
	else if (ft_intcmp(stack_a->top->next->content, max) == 0)
		rra(stack_a);
	if (ft_intcmp(stack_a->top->content, stack_a->top->next->content) > 0)
		sa(stack_a);
}
