/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/17 13:35:08 by klakbuic         ###   ########.fr       */
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

static void	push_all_2b(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	int		start_chunk;
	int		end_chunk;
	int		mid;
	int		chunk_size;
	int		*nb_a;
	int		flag;
	t_list	*head;
	int		i;

	// chunk_size = stack_a->size / chunks;
	chunk_size = get_chunck_size(stack_a);
	start_chunk = 1;
	end_chunk = chunk_size;
	mid = end_chunk / 2;
	flag = stack_a->size;
	// printf("stack a size: %d\n", stack_a->size);
	// printf("chuck size:%d\n", chunk_size);
	// printf("start: %d\n", start_chunk);
	// printf("end: %d\n", end_chunk);
	while (stack_a->size > 2)
	{
		head = stack_a->top;
		i = 0;
		while (head != NULL && stack_b->size < end_chunk)
		{
			if (ft_intcmp(head->content, &start_chunk) >= 0
				&& ft_intcmp(head->content, &end_chunk) <= 0)
			{
				if (i >= (stack_a->size / 2))
				{
					while (!(ft_intcmp(stack_a->top->content, &start_chunk) >= 0
							&& ft_intcmp(stack_a->top->content,
								&end_chunk) <= 0))
						rra(stack_a);
				}
				else
				{
					while (!(ft_intcmp(stack_a->top->content, &start_chunk) >= 0
							&& ft_intcmp(stack_a->top->content,
								&end_chunk) <= 0))
						ra(stack_a);
				}
				nb_a = ft_stack_top(stack_a);
				// printf("a top:%d\n", *nb_a);
				// printf("mid: %d\n", mid);
				pb(stack_a, stack_b);
				if (ft_intcmp(stack_b->top->content, &mid) >= 0)
				{
					if (stack_a->top && !(ft_intcmp(stack_a->top->content,
								&start_chunk) >= 0
							&& ft_intcmp(stack_a->top->content,
								&end_chunk) <= 0))
						rr(stack_a, stack_b);
					else
						rb(stack_b);
				}
				head = stack_a->top;
				i = 0;
			}
			else
			{
				head = head->next;
				i++;
			}
		}
		start_chunk = end_chunk + 1;
		end_chunk += get_chunck_size(stack_a);
		// printf("chunck size: %d\n", get_chunck_size(stack_a));
		// printf("end chunck: %d\n", end_chunk);
		if (end_chunk > flag)
			end_chunk = flag;
		mid = (end_chunk + start_chunk) / 2;
	}
}

static int ft_closet(int nb, int nb2, int *i, t_stack *stack_b)
{
	
}

static void	push_back_2a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head;
	int		nb;
	int		i;
	int		nb2;

	nb = stack_b->size;
	nb2 = nb - 1;
	while (nb > 0)
	{
		i = 0;
		head = stack_b->top;
		while (head != NULL)
		{
			if (ft_intcmp(head->content, &nb) == 0 || ft_intcmp(head->content, &nb2) == 0)
			{
				ft_closet(nb, nb2, i);
				if (i >= (stack_b->size / 2))
				{
					while (ft_intcmp(stack_b->top->content, &nb) != 0)
						rrb(stack_b);
				}
				else
				{
					while (ft_intcmp(stack_b->top->content, &nb) != 0)
						rb(stack_b);
				}
				pa(stack_b, stack_a);
				break ;
			}
			head = head->next;
			i++;
		}
		nb--;
		// printf("index: %d\n", i);
		// int *dig = stack_a->top->content;
		// printf("stack a->top: %d\n", *dig);
		// printf("nb: %d\n", nb);
	}
}

void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		ft_small_sort(stack_a);
	else if (stack_a->size <= 100)
	{
		push_all_2b(stack_a, stack_b, 4);
		push_back_2a(stack_a, stack_b);
	}
	else
	{
		push_all_2b(stack_a, stack_b, 8);
		push_back_2a(stack_a, stack_b);
	}
}