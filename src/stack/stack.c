/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoto-ga <dsoto-ga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:47:34 by dsoto-ga          #+#    #+#             */
/*   Updated: 2026/09/16 17:52:10 by dsoto-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

t_node	*stack_new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_bottom(t_stack *s, t_node *node)
{
	if (!s->top)
	{
		s->top = node;
		s->bottom = node;
	}
	else
	{
		node->prev = s->bottom;
		s->bottom->next = node;
		s->bottom = node;
	}
	s->size++;
}

void	stack_clear(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack_init(s);
}
