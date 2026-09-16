/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:35:46 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 18:46:18 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	debug_putnbr(int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		debug_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

static void	debug_print(t_stack *s)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		debug_putnbr(cur->content);
		write(1, "\n", 1);
		cur = cur->next;
	}
}

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
	debug_print(&ctx.a);
	stack_clear(&ctx.a);
	stack_clear(&ctx.b);
	return (0);
}
