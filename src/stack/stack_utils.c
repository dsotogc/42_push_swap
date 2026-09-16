/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:35:54 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 19:50:37 by dsoto-ga         ###   ########.fr       */
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
