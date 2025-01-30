/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 11:31:15 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-01-27 11:31:15 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top == NULL)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top != NULL)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	node->next = a->top;
	if (a->top != NULL)
		a->top->prev = node;
	else
		a->bottom = node;
	a->top = node;
	node->prev = NULL;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->top == NULL)
		return ;
	node = a->top;
	a->top = node->next;
	if (a->top != NULL)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	node->next = b->top;
	if (b->top != NULL)
		b->top->prev = node;
	else
		b->bottom = node;
	b->top = node;
	node->prev = NULL;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}
