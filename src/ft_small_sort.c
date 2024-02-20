/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:23:51 by khalid            #+#    #+#             */
/*   Updated: 2024/02/20 15:53:17 by klakbuic         ###   ########.fr       */
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

void	ft_sort_three(t_stack *stack_a)
{
	void	*max;

	max = get_max(stack_a);
	if (ft_intcmp(stack_a->top->content, max) == 0)
		ra(stack_a);
	else if (ft_intcmp(stack_a->top->next->content, max) == 0)
		rra(stack_a);
	if (ft_intcmp(stack_a->top->content, stack_a->top->next->content) > 0)
		sa(stack_a);
}

static void	*get_min(t_stack *stack_a)
{
	t_list	*head;
	void	*min;

	head = stack_a->top;
	min = head->content;
	while (head != NULL)
	{
		if (ft_intcmp(head->content, min) < 0)
			min = head->content;
		head = head->next;
	}
	return (min);
}
static void	push_min_2b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head;
	int		*min;
	int		i;

	head = stack_a->top;
	min = get_min(stack_a);
	i = 0;
	while (head != NULL)
	{
		if (ft_intcmp(stack_a->top->content, min) == 0)
		{
			if (i > (stack_a->size / 2))
				while (ft_intcmp(stack_a->top->content, min) != 0)
					rra(stack_a);
			else
				while (ft_intcmp(stack_a->top->content, min) != 0)
					ra(stack_a);
			pb(stack_a, stack_b);
		}
		else
		{
			head = head->next;
			i++;
		}
	}
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_min_2b(stack_a, stack_b);
	push_min_2b(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_b, stack_b);
	pa(stack_b, stack_a);
}
