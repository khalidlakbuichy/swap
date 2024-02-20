/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rpush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:31 by khalid            #+#    #+#             */
/*   Updated: 2024/02/19 13:22:43 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	ft_stack_rpush(t_stack *stack, void *data)
{
	bool	feedback;

	if (stack == NULL)
		return (false);
	feedback = ft_lstadd_back(&stack->top, ft_lstnew(data));
	if (feedback == true)
	{
		stack->size++;
		return (true);
	}
	return (false);
}
