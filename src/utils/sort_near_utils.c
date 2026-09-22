/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_near_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:02:38 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/22 14:44:58 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	near_min_pos(t_stack *a)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_val;

	cur = a->top;
	pos = 0;
	best_pos = 0;
	best_val = INT_MAX;
	while (cur)
	{
		if (cur->index < best_val)
		{
			best_val = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best_pos);
}

int	near_target_pos(t_stack *a, int value)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_val;

	cur = a->top;
	pos = 0;
	best_pos = -1;
	best_val = INT_MAX;
	while (cur)
	{
		if (cur->index > value && cur->index < best_val)
		{
			best_val = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (best_pos == -1)
		return (near_min_pos(a));
	return (best_pos);
}

void	near_rotate_to_top(t_context *ctx, int pos)
{
	int	size;
	int	i;

	size = ctx->a.size;
	i = 0;
	if (pos * 2 <= size)
		while (i++ < pos)
			ra(ctx);
	else
		while (i++ < size - pos)
			rra(ctx);
}
