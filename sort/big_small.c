/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:18:48 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:18:49 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_biggest(t_stack *to_search, int n)
{
	t_node	*curr;

	if (!to_search->top)
		return (INT_MIN);
	curr = to_search->top;
	while (curr)
	{
		if (n < curr->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_smallest(t_stack *to_search, int n)
{
	t_node	*curr;

	if (!to_search->top)
		return (INT_MIN);
	curr = to_search->top;
	while (curr)
	{
		if (n > curr->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	get_biggest(t_stack	*to_search)
{
	t_node	*curr;
	int		max;

	if (!to_search->top)
		return (INT_MIN);
	curr = to_search->top;
	max = curr->val;
	while (curr)
	{
		if (max < curr->val)
			max = curr->val;
		curr = curr->next;
	}
	return (max);
}

int	get_smallest(t_stack *to_search)
{
	t_node	*curr;
	int		min;

	if (!to_search)
		return (INT_MAX);
	curr = to_search->top;
	min = curr->val;
	while (curr)
	{
		if (min > curr->val)
			min = curr->val;
		curr = curr->next;
	}
	return (min);
}
