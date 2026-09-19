/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:10:00 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/19 16:27:19 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	put_field(char *label, int value)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(value, 2);
}

void	put_bench_ops(t_counters *o)
{
	put_field("\n[bench] sa: ", o->sa);
	put_field(" sb: ", o->sb);
	put_field(" ss: ", o->ss);
	put_field(" pa: ", o->pa);
	put_field(" pb: ", o->pb);
	put_field("\n[bench] ra: ", o->ra);
	put_field(" rb: ", o->rb);
	put_field(" rr: ", o->rr);
	put_field(" rra: ", o->rra);
	put_field(" rrb: ", o->rrb);
	put_field(" rrr: ", o->rrr);
}
