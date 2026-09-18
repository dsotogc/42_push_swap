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

void	push_stack(t_stack *dest, t_stack *src)
{
	t_node	*node;

	if (!src->top)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = NULL;
	node->prev = NULL;
	stack_add_top(dest, node);
}

void	swap_stack(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (stack->size < 2)
		return ;
	a = stack->top;
	b = a->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	else
		stack->bottom = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	stack->top = b;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*old_top;

	if (stack->size < 2)
		return ;
	old_top = stack->top;
	stack->top = old_top->next;
	stack->top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*old_bottom;

	if (stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
}
