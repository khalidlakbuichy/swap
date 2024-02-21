/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:47:48 by klakbuic          #+#    #+#             */
/*   Updated: 2024/02/21 13:39:39 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partitioning(int *arr, int start_index, int end_index)
{
	int	i;
	int	j;
	int	pivot;

	i = start_index - 1;
	pivot = arr[end_index];
	j = start_index;
	while (j <= (end_index - 1))
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[end_index]);
	return (i + 1);
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = partitioning(arr, start, end);
		quick_sort(arr, start, (pivot_index - 1));
		quick_sort(arr, (pivot_index + 1), end);
	}
}

void	ft_qsort(int *arr, unsigned int size)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = size - 1;
	quick_sort(arr, start, end);
}
