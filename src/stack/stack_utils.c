/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otsrpl <otsrpl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:35:54 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/20 00:38:44 by otsrpl           ###   ########.fr       */
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

double	compute_disorder(t_stack *s)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	if (!s || s->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content > j->content)
				mistakes++;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / total_pairs);
}
