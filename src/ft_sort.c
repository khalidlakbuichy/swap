/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/20 15:09:24 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	update_chunk(t_chunk *chunk, t_stack *stack_a)
{
	chunk->start = chunk->end + 1;
	chunk->end += get_chunck_size(stack_a);
	if (chunk->end > chunk->max)
		chunk->end = chunk->max;
	chunk->mid = (chunk->end + chunk->start) / 2;
}

static void	setup_chunk(t_chunk *chunk, t_stack *stack_a)
{
	chunk->start = 1;
	chunk->end = get_chunck_size(stack_a);
	chunk->mid = chunk->end / 2;
	chunk->max = stack_a->size;
}

static void	push_all_2b(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	t_list	*head;
	int		i;

	setup_chunk(&chunk, stack_a);
	while (stack_a->size > 0)
	{
		head = stack_a->top;
		i = 0;
		while (head != NULL && stack_b->size < chunk.end)
		{
			if (is_in_range(head->content, &chunk.start, &chunk.end))
			{
				put_top_push(stack_a, stack_b, i, &chunk);
				head = stack_a->top;
				i = 0;
			}
			else
			{
				head = head->next;
				i++;
			}
		}
		if (stack_b->size == chunk.end)
			update_chunk(&chunk, stack_a);
	}
}

static void	push_back_2a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head;
	int		nb;
	int		i;

	nb = stack_b->size + 1;
	while (--nb > 0)
	{
		i = 0;
		head = stack_b->top;
		while (head != NULL)
		{
			if (ft_intcmp(head->content, &nb) == 0)
			{
				if (i >= (stack_b->size / 2))
					while (ft_intcmp(stack_b->top->content, &nb) != 0)
						rrb(stack_b);
				else
					while (ft_intcmp(stack_b->top->content, &nb) != 0)
						rb(stack_b);
				pa(stack_b, stack_a);
				break ;
			}
			head = head->next;
			i++;
		}
	}
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		ft_small_sort(stack_a);
	else
	{
		push_all_2b(stack_a, stack_b);
		push_back_2a(stack_a, stack_b);
	}
}
