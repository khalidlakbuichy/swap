/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/14 16:39:02 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_all_2b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	start_chunk;
	int	end_chunk;
	int	mid;

	start_chunk = 0;
	end_chunk = stack_a->size / chunk_size;
	mid = end_chunk / 2;
	printf("start: %d\n", start_chunk);
	printf("end: %d\n", end_chunk);
	printf("mid: %d\n", mid);
	while (stack_a->size > 0)
	{
		while (stack_b->size <= end_chunk)
		{
			if (ft_intcmp(ft_stack_top(stack_a), &start_chunk) >= 0 && ft_intcmp(ft_stack_top(stack_a), &end_chunk))
			{
				printf("stack_b->size: %d\n", stack_b->size);
				usleep(500);
				// printf("stack b size: %d\n", stack_b->size);
				pb(stack_a, stack_b);
				// printf("size b: %d\n", stack_b->size);
				if (ft_intcmp(ft_stack_top(stack_a), &mid) >= 0)
					rb(stack_b);
			}
			else
			{
				ra(stack_a);
				usleep(500);
			}
		}
		start_chunk = end_chunk;
		end_chunk += end_chunk;
		mid = (end_chunk / 2);
		printf("start: %d\n", start_chunk);
		printf("end: %d\n", end_chunk);
		printf("mid: %d\n", mid);
	}
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	push_all_2b(stack_a, stack_b, chunk_size);
}