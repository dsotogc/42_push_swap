/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 16:05:59 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 16:19:44 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_overflows(char *n)
{
	long	value;
	long	sign;
	int		i;

	value = 0;
	sign = 1;
	i = 0;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		value = value * 10 + (n[i] - '0');
		if (value * sign > INT_MAX || value * sign < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isvalid(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '+' || n[i] == '-')
		i++;
	if (!n[i])
		return (0);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (!ft_overflows(n));
}

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}
