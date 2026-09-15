/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:35:46 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/15 17:22:24 by dsoto-ga         ###   ########.fr       */
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
		write(2, "Error\n", 6);
		return (1);
	}
	write(1, "Ha pasado el parseo correctamente\n", 34);
	return (0);
}
