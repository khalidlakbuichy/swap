/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/02 12:19:23 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_check_args(int ac, char **av)
{
	int i;
	int j;
	int error_flag;
	char **splited_av;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_print_error();
		splited_av = ft_split(av[i], ' ');
		j = 0;
		if (splited_av[j] == NULL)
		{
			/* add this number to the stack */
			printf("%d\n", ft_atoi_enhanced(av[i], &error_flag));
			/* if error == 1 print error and free the stack */
			if (error_flag)
				ft_print_error();
		}
		while (splited_av[j] != NULL)
		{
			printf("%d\n", ft_atoi_enhanced(splited_av[j], &error_flag));
			if (error_flag)
				ft_print_error();
			j++;
		}
		i++;
	}
}
