/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:11:11 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/20 11:08:18 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_intcmp(void *ref, void *data)
{
	int	*nb_a;
	int	*nb_b;

	nb_a = ref;
	nb_b = data;
	if (*nb_a > *nb_b)
		return (1);
	else if (*nb_a < *nb_b)
		return (-1);
	else
		return (0);
}

int	get_chunck_size(t_stack *stack_a)
{
	if (stack_a->size > 300)
		return (stack_a->size / 7);
	else if (stack_a->size > 100)
		return (stack_a->size / 5);
	else if (stack_a->size > 3)
		return (stack_a->size / 4);
	else
		return (stack_a->size);
}

int	is_in_range(void *data, void *start, void *end)
{
	return (ft_intcmp(data, start) >= 0 && ft_intcmp(data, end) <= 0);
}

void	put_top_push(t_stack *stack_a, t_stack *stack_b, int i, t_chunk *chunk)
{
	if (i >= (stack_a->size / 2))
	{
		while (!is_in_range(stack_a->top->content, &chunk->start, &chunk->end))
			rra(stack_a);
	}
	else
	{
		while (!is_in_range(stack_a->top->content, &chunk->start, &chunk->end))
		{
			if (stack_b->top && ft_intcmp(stack_b->top->content,
					&chunk->mid) >= 0)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	pb(stack_a, stack_b);
}

int	ft_is_sorted(t_stack *stack_a)
{
	t_list	*head;

	head = stack_a->top;
	while (head->next != NULL)
	{
		if (ft_intcmp(head->content, (head->next)->content) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
