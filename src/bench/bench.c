/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:37:22 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/19 16:27:06 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	total_ops(t_context *ctx)
{
	t_counters	*o;

	o = &ctx->ops;
	return (o->sa + o->sb + o->ss + o->pa + o->pb + o->ra
		+ o->rb + o->rr + o->rra + o->rrb + o->rrr);
}

static void	put_disorder(double disorder)
{
	int	scaled;

	scaled = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(scaled / 100, 2);
	ft_putstr_fd(".", 2);
	if (scaled % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(scaled % 100, 2);
	ft_putstr_fd("%", 2);
}

static void	put_strategy(t_context *ctx)
{
	if (ctx->strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (ctx->strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n*sqrt(n))", 2);
	else if (ctx->strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else if (ctx->disorder < 0.2)
		ft_putstr_fd("Adaptive / O(n)", 2);
	else if (ctx->disorder < 0.5)
		ft_putstr_fd("Adaptive / O(n*sqrt(n))", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)", 2);
}

void	print_bench(t_context *ctx)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_disorder(ctx->disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	put_strategy(ctx);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(ctx), 2);
	put_bench_ops(&ctx->ops);
	ft_putstr_fd("\n", 2);
}
