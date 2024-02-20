/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:23:47 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/19 13:22:26 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_list	*head;

	head = stack_a->top;
	while (head->next != NULL)
	{
		if (ft_intcmp(head->content, head->next->content) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
