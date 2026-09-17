/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:22:06 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/17 17:31:41 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	push_stack(t_stack *dest, t_stack *src)
{
	t_node	*node;

	node = src->top;
	src->top = src->top->next;
	src->top->prev = NULL;
	stack_add_top(dest, node);
	src->size--;
	return (0);
}

int	swap_stack(t_stack *stack)
{
	t_node	*aux;

	aux = stack->top->next->next;
	aux->prev = stack->top;
	stack->top->next->next = stack->top;
	stack->top->next->prev = NULL;
	stack->top->prev = stack->top->next;
	stack->top->next = aux;
	stack->top = stack->top->prev;
	return (0);
}

int	rotate_stack(t_stack *stack)
{
	t_node	*aux;

	aux = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	aux->prev = NULL;
	stack->top = aux;
	return (0);
}

int	reverse_rotate_stack(t_stack *stack)
{
	t_node	*aux;

	aux = stack->bottom->prev;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top->prev = NULL;
	aux->next = NULL;
	stack->bottom = aux;
	return (0);
}
