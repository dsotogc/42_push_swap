/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_near.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:41:24 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/22 14:45:02 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	extract_errors(t_context *ctx)
{
	int	i;
	int	n;
	int	last;

	n = ctx->a.size;
	i = 0;
	last = -1;
	while (i < n)
	{
		if (ctx->a.top->index > last)
		{
			last = ctx->a.top->index;
			ra(ctx);
		}
		else
			pb(ctx);
		i++;
	}
}

static void	reinsert(t_context *ctx)
{
	int	pos;

	while (ctx->b.size > 0)
	{
		pos = near_target_pos(&ctx->a, ctx->b.top->index);
		near_rotate_to_top(ctx, pos);
		pa(ctx);
	}
}

void	sort_near(t_context *ctx)
{
	if (ctx->a.size < 2)
		return ;
	extract_errors(ctx);
	reinsert(ctx);
	near_rotate_to_top(ctx, near_min_pos(&ctx->a));
}
