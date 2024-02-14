/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:51:23 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/14 10:16:54 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// static int	elm_cmp(void *elm1, void *elm2)
// {
// 	t_element	*elma;
// 	t_element	*elmb;

// 	elma = elm1;
// 	elmb = elm2;
//     if (elma->nb <= elmb->nb)
//         return (1);
//     return (0);
// }

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

// void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int pivot;
// 	t_list *head;

// 	head = stack_a->top;
// 	stack_b->top = NULL;
// 	pivot = stack_a->size / 2;
// 	while (head != NULL)
// 	{
// 		if (ft_intcmp(&pivot, head->content) > 0)
// 		{
// 			if (head == stack_a->top)
// 				pb(stack_a, stack_b);
// 			else
// 			{
// 				while ()
// 				{
// 					/* code */
// 				}

// 			}
// 		}
// 		head = head->next;
// 	}

// }