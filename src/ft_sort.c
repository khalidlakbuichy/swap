/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/15 09:30:11 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	push_top_2b(t_stack *stack_a, t_stack *stack_b, int *mid)
{
	int *nb_top;

	nb_top = ft_stack_top(stack_a);
	pb(stack_a, stack_b);
	if (ft_intcmp(nb_top, mid) >= 0)
		rb(stack_b);
}
static void	push_all_2b(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	int	start_chunk;
	int	end_chunk;
	int	mid;
	int	chunk_size;
	int	*nb_a;

	chunk_size = stack_a->size / chunks;
	start_chunk = 1;
	end_chunk = chunk_size;
	mid = end_chunk / 2;
	printf("start: %d\n", start_chunk);
	printf("end: %d\n", end_chunk);
	printf("mid: %d\n", mid);
	while (stack_a->size > 0)
	{
		while (stack_b->size < end_chunk)
		{
			nb_a = ft_stack_top(stack_a);
			printf("a top:%d\n", *nb_a);
			if (ft_intcmp(ft_stack_top(stack_a), &start_chunk) >= 0
				&& ft_intcmp(ft_stack_top(stack_a), &end_chunk) <= 0)
				push_top_2b(stack_a, stack_b, &mid);
			else
				ra(stack_a);
		}
		start_chunk = end_chunk + 1;
		end_chunk += chunk_size;
		mid = (end_chunk / 2);
	}
	printf("stack a size: %d\n", stack_a->size);
	printf("stack b size: %d\n", stack_b->size);
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	push_all_2b(stack_a, stack_b, chunks);
}