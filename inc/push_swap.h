/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:21:56 by khalid            #+#    #+#             */
/*   Updated: 2024/02/05 10:04:00 by khalid           ###   ########.fr       */
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

int		ft_atoi_enhanced(char *str, int *error_flag);
void	ft_check_args(int ac, char **av, t_stack *stack_a);

/* Stack operations */
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack);
void	ft_rrotate(t_stack *stack);
#endif
