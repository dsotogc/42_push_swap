/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:03:41 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/21 17:39:29 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_adaptive(t_context *ctx)
{
	if (ctx->disorder < 0.2)
		sort_complex(ctx);
	else if (ctx->disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
