/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/22 10:30:17 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	update_chunk(t_chunk *chunk, t_stack *a)
{
	chunk->start = chunk->end + 1;
	chunk->end += get_chunck_size(a);
	if (chunk->end > chunk->max)
		chunk->end = chunk->max;
	chunk->mid = (chunk->end + chunk->start) / 2;
}

static void	setup_chunk(t_chunk *chunk, t_stack *a)
{
	chunk->start = 1;
	chunk->end = get_chunck_size(a);
	chunk->mid = chunk->end / 2;
	chunk->max = a->size;
}

static void	push_all_2b(t_stack *a, t_stack *b)
{
	t_chunk	chunk;
	t_list	*head;
	int		i;

	setup_chunk(&chunk, a);
	while (a->size > 0)
	{
		head = a->top;
		i = 0;
		while (head != NULL && b->size < chunk.end)
		{
			if (is_in_range(head->content, &chunk.start, &chunk.end))
			{
				put_top_push(a, b, i, &chunk);
				break ;
			}
			else
			{
				head = head->next;
				i++;
			}
		}
		if (b->size == chunk.end)
			update_chunk(&chunk, a);
	}
}

static void	push_back_2a(t_stack *a, t_stack *b)
{
	t_list	*head;
	int		nb2;
	int		nb;
	int		i;

	nb = b->size;
	nb2 = nb - 1;
	while (nb > 0)
	{
		i = -1;
		head = b->top;
		while (head != NULL && ++i >= 0)
		{
			if (cmp(head->content, &nb) == 0 || cmp(head->content, &nb2) == 0)
			{
				put_elem_top(b, i, &nb, &nb2);
				put_elem_2a(a, b, &nb, &nb2);
				break ;
			}
			head = head->next;
		}
	}
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		ft_sort_three(a);
	else if (a->size < 6)
		ft_sort_five(a, b);
	else
	{
		push_all_2b(a, b);
		push_back_2a(a, b);
	}
}
