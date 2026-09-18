/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:22:12 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/18 17:42:42 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_context *ctx)
{
	reverse_rotate_stack(&ctx->a);
	write(1, "rra\n", 4);
	ctx->ops.rra++;
}

void	rrb(t_context *ctx)
{
	reverse_rotate_stack(&ctx->b);
	write(1, "rrb\n", 4);
	ctx->ops.rrb++;
}

void	rrr(t_context *ctx)
{
	reverse_rotate_stack(&ctx->a);
	reverse_rotate_stack(&ctx->b);
	write(1, "rrr\n", 4);
	ctx->ops.rrr++;
}
