/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:49:38 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/17 10:46:56 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

bool	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL || lst == NULL)
		return (false);
	if (*lst == NULL)
	{
		*lst = new;
		return (true);
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
	return (true);
}
