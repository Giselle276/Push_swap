/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 13:49:50 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-01-27 13:49:50 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*node;

	if (!b->top || b->top == b->bottom)
		return ;
	node = b->bottom;
	b->bottom = node->prev;
	b->bottom->next = NULL;
	node->prev = NULL;
	node->next = b->top;
	b->top->prev = node;
	b->top = node;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*node2;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	if (!b->top || b->top == b->bottom)
		return ;
	node2 = b->bottom;
	b->bottom = node2->prev;
	b->bottom->next = NULL;
	node2->prev = NULL;
	node2->next = b->top;
	b->top->prev = node2;
	b->top = node2;
	write(1, "rrr\n", 4);
}
