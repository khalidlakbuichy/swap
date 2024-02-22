/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:23:47 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/22 10:10:28 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	cmp(void *ref, void *data)
{
	int	*nb_a;
	int	*nb_b;

	nb_a = ref;
	nb_b = data;
	if (*nb_a > *nb_b)
		return (1);
	else if (*nb_a < *nb_b)
		return (-1);
	else
		return (0);
}

int	ft_is_sorted(t_stack *a)
{
	t_list	*head;

	head = a->top;
	while (head->next != NULL)
	{
		if (cmp(head->content, head->next->content) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
