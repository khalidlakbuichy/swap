/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/18 11:07:10 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_top_2b(t_stack *stack_a, t_stack *stack_b, int *mid)
{
	int	*nb_top;

	nb_top = ft_stack_top(stack_a);
	pb(stack_a, stack_b);
	if (ft_intcmp(nb_top, mid) > 0)
		rb(stack_b);
}

static int	get_chunck_size(t_stack *stack_a)
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

static int	is_in_range(void *data, void *start, void *end)
{
	return (ft_intcmp(data, start) >= 0 && ft_intcmp(data, end) <= 0);
}

static void	put_top(t_stack *stack_a, t_stack *stack_b, int i, t_chunk *chunk)
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
			if (stack_b->top && ft_intcmp(stack_b->top->content, &chunk->mid) >= 0)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	pb(stack_a, stack_b);
}

static void	setup_chunk(t_chunk *chunk, t_stack *stack_a)
{
	chunk->start = chunk->end + 1;
	chunk->end += get_chunck_size(stack_a);
	if (chunk->end > chunk->max)
		chunk->end = chunk->max;
	chunk->mid = (chunk->end + chunk->start) / 2;
}

static void	push_all_2b(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	chunk;
	t_list	*head;
	int		i;

	chunk.start = 1;
	chunk.end = get_chunck_size(stack_a);
	chunk.mid = chunk.end / 2;
	chunk.max = stack_a->size;
	while (stack_a->size > 2)
	{
		head = stack_a->top;
		i = 0;
		while (head != NULL && stack_b->size < chunk.end)
		{
			if (is_in_range(head->content, &chunk.start, &chunk.end))
			{
				put_top(stack_a, stack_b, i, &chunk);
				head = stack_a->top;
				i = 0;
			}
			else
			{
				head = head->next;
				i++;
			}
		}
		setup_chunk(&chunk, stack_a);
	}
}

static void	push_back_2a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head;
	int		nb;
	int		i;

	nb = stack_b->size;
	while (nb > 0)
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
		nb--;
	}
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		ft_small_sort(stack_a);
	else if (stack_a->size <= 100)
	{
		push_all_2b(stack_a, stack_b);
		push_back_2a(stack_a, stack_b);
	}
	else
	{
		push_all_2b(stack_a, stack_b);
		push_back_2a(stack_a, stack_b);
	}
}