/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:23:51 by khalid            #+#    #+#             */
/*   Updated: 2024/02/22 09:48:30 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	*get_max(t_stack *a)
{
	t_list	*head;
	void	*max;

	head = a->top;
	max = head->content;
	while (head != NULL)
	{
		if (cmp(head->content, max) > 0)
			max = head->content;
		head = head->next;
	}
	return (max);
}

void	ft_sort_three(t_stack *a)
{
	void	*max;

	max = get_max(a);
	if (cmp(a->top->content, max) == 0)
		ra(a);
	else if (cmp(a->top->next->content, max) == 0)
		rra(a);
	if (cmp(a->top->content, a->top->next->content) > 0)
		sa(a);
}

static void	*get_min(t_stack *a)
{
	t_list	*head;
	void	*min;

	head = a->top;
	min = head->content;
	while (head != NULL)
	{
		if (cmp(head->content, min) < 0)
			min = head->content;
		head = head->next;
	}
	return (min);
}

static void	push_min_2b(t_stack *a, t_stack *b)
{
	t_list	*head;
	int		*min;
	int		i;

	head = a->top;
	min = get_min(a);
	i = 0;
	while (head != NULL)
	{
		if (cmp(head->content, min) == 0)
		{
			if (i > (a->size / 2))
				while (cmp(a->top->content, min) != 0)
					rra(a);
			else
				while (cmp(a->top->content, min) != 0)
					ra(a);
			pb(a, b);
			return ;
		}
		head = head->next;
		i++;
	}
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	push_min_2b(a, b);
	push_min_2b(a, b);
	ft_sort_three(a);
	pa(b, a);
	pa(b, a);
}
