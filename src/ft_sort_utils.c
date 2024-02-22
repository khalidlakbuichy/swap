/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:11:11 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/22 09:48:30 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	cmp(void *ref, void *data)
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

int	get_chunck_size(t_stack *a)
{
	if (a->size > 100)
		return (a->size / 7);
	else if (a->size > 3)
		return (a->size / 4);
	else
		return (1);
}

int	is_in_range(void *data, void *start, void *end)
{
	return (cmp(data, start) >= 0 && cmp(data, end) <= 0);
}

void	put_top_push(t_stack *a, t_stack *b, int i, t_chunk *chunk)
{
	if (i >= (a->size / 2))
	{
		while (!is_in_range(a->top->content, &chunk->start, &chunk->end))
			rra(a);
	}
	else
	{
		while (!is_in_range(a->top->content, &chunk->start, &chunk->end))
		{
			if (b->top && cmp(b->top->content, &chunk->mid) >= 0)
				rr(a, b);
			else
				ra(a);
		}
	}
	pb(a, b);
}

int	ft_is_sorted(t_stack *a)
{
	t_list	*head;

	head = a->top;
	while (head->next != NULL)
	{
		if (cmp(head->content, (head->next)->content) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
