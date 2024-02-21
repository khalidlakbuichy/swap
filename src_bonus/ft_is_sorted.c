/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:23:47 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/21 11:38:12 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_list	*head;

	head = a->top;
	while (head->next != NULL)
	{
		if (ft_intcmp(head->content, head->next->content) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
