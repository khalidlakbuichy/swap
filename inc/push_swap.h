/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:21:56 by khalid            #+#    #+#             */
/*   Updated: 2024/02/18 10:10:33 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/ft_containers/ft_data_structres.h"
# include "../libs/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* struct for chuncks data: the start of the chunck the middle and the end */
typedef struct s_chunk
{
	int	start;
	int	mid;
	int	end;
	int	max;
}		t_chunk;

/* Error handling */
int		ft_atoi_enhanced(char *str);
void	ft_print_error(void);
void	ft_check_args(int ac, char **av, t_stack *stack_a);

/* operations */
bool	ft_stack_rpush(t_stack *stack, void *data);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Sorting algorithm */
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b);
int		ft_is_sorted(t_stack *stack_a);
void	ft_qsort(int *arr, unsigned int size);
int		ft_intcmp(void *ref, void *data);
void	ft_small_sort(t_stack *stack_a);

#endif
