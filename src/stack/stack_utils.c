/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:35:54 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/17 15:24:51 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	index_stack(t_stack *s)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = s->top;
	while (i)
	{
		rank = 0;
		j = s->top;
		while (j)
		{
			if (j->content < i->content)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

int	stack_has_duplicates(t_stack *s)
{
	t_node	*i;
	t_node	*j;

	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
