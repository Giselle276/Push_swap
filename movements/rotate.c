/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 11:47:58 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-01-27 11:47:58 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*node;

	if (!b->top || b->top == b->bottom)
		return ;
	node = b->top;
	b->top = node->next;
	b->top->prev = NULL;
	b->bottom->next = node;
	node->prev = b->bottom;
	node->next = NULL;
	b->bottom = node;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*node2;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	if (!b->top || b->top == b->bottom)
		return ;
	node2 = b->top;
	b->top = node2->next;
	b->top->prev = NULL;
	b->bottom->next = node2;
	node2->prev = b->bottom;
	node2->next = NULL;
	b->bottom = node2;
	write(1, "rr\n", 3);
}
