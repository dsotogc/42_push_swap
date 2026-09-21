/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:35:46 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/20 19:36:05 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_context	ctx;

	if (argc < 2)
		return (0);
	if (parse_args(argc, argv, &ctx))
	{
		stack_clear(&ctx.a);
		stack_clear(&ctx.b);
		write(2, "Error\n", 6);
		return (1);
	}
	index_stack(&ctx.a);
	ctx.disorder = compute_disorder(&ctx.a);
	if (ctx.strategy == STRAT_COMPLEX)
		sort_complex(&ctx);
	else
		sort_simple(&ctx);
	stack_clear(&ctx.a);
	stack_clear(&ctx.b);
	if (ctx.bench_mode)
		print_bench(&ctx);
	return (0);
}
