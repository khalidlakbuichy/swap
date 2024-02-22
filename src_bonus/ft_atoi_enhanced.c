/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_enhanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klakbuic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:11:04 by khalid            #+#    #+#             */
/*   Updated: 2024/02/22 10:06:07 by klakbuic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#define MAX_INT_LEN 10
#define INT_MAX "2147483647"
#define INT_MIN "2147483648"

static int	is_white(int c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static int	check_int_overflow(char *nbr, int signe)
{
	if (ft_strlen(nbr) < MAX_INT_LEN)
		return (0);
	if (ft_strlen(nbr) > MAX_INT_LEN)
		return (1);
	if (ft_strlen(nbr) == MAX_INT_LEN)
	{
		if (signe > 0)
			if (ft_strncmp(nbr, INT_MAX, MAX_INT_LEN) <= 0)
				return (0);
		if (signe < 0)
			if (ft_strncmp(nbr, INT_MIN, MAX_INT_LEN) <= 0)
				return (0);
	}
	return (1);
}

int	ft_atoi_enhanced(char *str, int *flag)
{
	int				signe;
	unsigned int	nb;

	signe = 1;
	nb = 0;
	*flag = 0;
	while (is_white(*str))
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (check_int_overflow(str, signe))
		return ((*flag = 1), 0);
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			nb = (nb * 10) + ((*str - '0'));
		else
			return ((*flag = 1), 0);
		str++;
	}
	return ((int)nb * signe);
}
