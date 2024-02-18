/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:39:37 by khalid            #+#    #+#             */
/*   Updated: 2024/02/18 11:21:49 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

bool	ft_stack_clear(t_stack *stack, void (*del)(void *))
{
	if (stack == NULL)
		return (false);
	ft_lstclear(&stack->top, del);
	free(stack);
	stack = NULL;
	return(true);
}
