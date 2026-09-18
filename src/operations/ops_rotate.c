/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:21:31 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/18 17:43:55 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_context *ctx)
{
	rotate_stack(&ctx->a);
	write(1, "ra\n", 3);
	ctx->ops.ra++;
}

void	rb(t_context *ctx)
{
	rotate_stack(&ctx->b);
	write(1, "rb\n", 3);
	ctx->ops.rb++;
}

void	rr(t_context *ctx)
{
	rotate_stack(&ctx->a);
	rotate_stack(&ctx->b);
	write(1, "rr\n", 3);
	ctx->ops.rr++;
}
