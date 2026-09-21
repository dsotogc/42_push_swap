/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 17:21:14 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/21 14:30:56 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_context *ctx, int bit)
{
	int	i;
	int	n;

	n = ctx->a.size;
	i = 0;
	while (i < n)
	{
		if (((ctx->a.top->index >> bit) & 1) == 0)
			pb(ctx);
		else
			ra(ctx);
		i++;
	}
	while (ctx->b.size > 0)
		pa(ctx);
}

void	sort_complex(t_context *ctx)
{
	int	max_bits;
	int	bit;

	if (ctx->a.size < 2)
		return ;
	index_stack(&ctx->a);
	max_bits = count_bits(ctx->a.size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(ctx, bit);
		bit++;
	}
}
