/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtapiado <rtapiado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:18:01 by rtapiado          #+#    #+#             */
/*   Updated: 2026/09/20 21:31:23 by rtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	get_max_pos(t_stack *b)
{
	t_node	*curr;
	int		max_index;
	int		max_pos;
	int		pos;

	if (!b || !b->top)
		return (-1);
	curr = b->top;
	max_index = curr->index;
	max_pos = 0;
	pos = 0;
	while (curr)
	{
		if (curr->index > max_index)
		{
			max_index = curr->index;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

static	void	push_to_b(t_context *ctx, int chunk_size)
{
	int	i;

	i = 0;
	while (ctx->a.size > 0)
	{
		if (ctx->a.top->index <= i)
		{
			pb(ctx);
			rb(ctx);
			i++;
		}
		else if (ctx->a.top->index <= i + chunk_size)
		{
			pb(ctx);
			i++;
		}
		else
			ra(ctx);
	}
}

static	void	push_to_a(t_context *ctx)
{
	int	max_pos;

	while (ctx->b.size > 0)
	{
		max_pos = get_max_pos(&ctx->b);
		if (max_pos <= ctx->b.size / 2)
		{
			while (max_pos > 0)
			{
				rb(ctx);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < ctx->b.size)
			{
				rrb(ctx);
				max_pos++;
			}
		}
		pa(ctx);
	}
}

void	sort_medium(t_context *ctx)
{
	int	chunk_size;

	if (ctx->a.size < 2)
		return ;
	chunk_size = ft_sqrt(ctx->a.size);
	push_to_b(ctx, chunk_size);
	push_to_a(ctx);
}
