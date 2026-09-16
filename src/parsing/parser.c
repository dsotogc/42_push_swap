/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:43:50 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 18:43:31 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}

static int	build_stack(char **arg, t_context *ctx)
{
	t_node	*node;

	while (*arg)
	{
		if (!ft_isvalid(*arg))
			return (-1);
		node = stack_new_node(ft_atoi(*arg));
		if (!node)
			return (-1);
		stack_add_bottom(&ctx->a, node);
		arg++;
	}
	return (0);
}

static int	identify_flag(char *arg, t_context *ctx)
{
	if (ctx->strategy != STRAT_UNDEFINED && ft_strcmp(arg, "--bench") != 0)
		return (-1);
	else
	{
		if (ft_strcmp(arg, "--complex") == 0)
			ctx->strategy = STRAT_COMPLEX;
		else if (ft_strcmp(arg, "--medium") == 0)
			ctx->strategy = STRAT_MEDIUM;
		else if (ft_strcmp(arg, "--simple") == 0)
			ctx->strategy = STRAT_SIMPLE;
		else if (ft_strcmp(arg, "--adaptive") == 0)
			ctx->strategy = STRAT_ADAPTIVE;
		else if (ft_strcmp(arg, "--bench") == 0)
			ctx->bench_mode = 1;
		else
			return (-1);
	}
	return (0);
}

static int	handle_numbers(char *arg, t_context *ctx)
{
	char	**tokenized_arg;
	int		res;

	tokenized_arg = ft_split(arg, ' ');
	if (!tokenized_arg)
		return (1);
	res = build_stack(tokenized_arg, ctx);
	free_split(tokenized_arg);
	if (res == -1)
		return (1);
	return (0);
}

int	parse_args(int argc, char *argv[], t_context *ctx)
{
	int	c;

	ctx->strategy = STRAT_UNDEFINED;
	ctx->bench_mode = 0;
	stack_init(&ctx->a);
	stack_init(&ctx->b);
	c = 1;
	while (c < argc)
	{
		if (argv[c][0] == '-' && argv[c][1] == '-')
		{
			if (identify_flag(argv[c], ctx) == -1)
				return (1);
		}
		else if (handle_numbers(argv[c], ctx) == 1)
			return (1);
		c++;
	}
	return (0);
}
