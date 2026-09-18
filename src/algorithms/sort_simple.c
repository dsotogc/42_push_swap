/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 18:05:12 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/18 20:36:53 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_simple(t_context *ctx)
{
	t_stack	*a;
	int		i;
	int		j;

	a = &ctx->a;
	i = 0;
	if (a->size < 2)
		return ;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (j < a->size - 1 && a->top->content > a->top->next->content)
				sa(ctx);
			ra(ctx);
			j++;
		}
		i++;
	}
}
