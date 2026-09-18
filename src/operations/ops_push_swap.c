/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:21:28 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/18 17:44:27 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_context *ctx)
{
	push_stack(&ctx->a, &ctx->b);
	write(1, "pa\n", 3);
	ctx->ops.pa++;
}

void	pb(t_context *ctx)
{
	push_stack(&ctx->b, &ctx->a);
	write(1, "pb\n", 3);
	ctx->ops.pb++;
}

void	sa(t_context *ctx)
{
	swap_stack(&ctx->a);
	write(1, "sa\n", 3);
	ctx->ops.sa++;
}

void	sb(t_context *ctx)
{
	swap_stack(&ctx->b);
	write(1, "sb\n", 3);
	ctx->ops.sb++;
}

void	ss(t_context *ctx)
{
	swap_stack(&ctx->a);
	swap_stack(&ctx->b);
	write(1, "ss\n", 3);
	ctx->ops.ss++;
}
