/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:26:48 by khalid            #+#    #+#             */
/*   Updated: 2024/02/22 10:32:01 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	split_free(char **splited_str)
{
	int	i;

	i = -1;
	if (splited_str == NULL)
		return ;
	while (splited_str[++i] != NULL)
		free(splited_str[i]);
	free(splited_str);
}

static void	push_nb_to_stack(t_stack *a, t_stack *b, char **sp, int nb)
{
	int	*nbr;

	if (ft_lstsearh_item(a->top, &nb, cmp))
	{
		ft_freestacks(a, b);
		split_free(sp);
		ft_print_error();
	}
	nbr = (int *)malloc(sizeof(int));
	if (nbr == NULL)
		return ;
	*nbr = nb;
	ft_stack_rpush(a, nbr);
}

void	ft_check_args(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		flag;
	char	**sp;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '\0')
			ft_print_error();
		sp = ft_split(av[i], ' ');
		j = 0;
		if (sp[j] == NULL)
			push_nb_to_stack(a, b, sp, ft_atoi_enhanced(av[i], &flag));
		while (sp[j] != NULL)
			push_nb_to_stack(a, b, sp, ft_atoi_enhanced(sp[j++], &flag));
		split_free(sp);
		if (flag == 1 && ft_freestacks(a, b))
			ft_print_error();
	}
}
