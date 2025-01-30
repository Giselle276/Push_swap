/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:46:12 by gmaccha-          #+#    #+#             */
/*   Updated: 2025-01-27 09:46:12 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_inmediate_lower(t_stack *to_search, int n)
{
	int		dif;
	int		target;
	t_node	*curr;

	if (!to_search->top)
		return (INT_MIN);
	dif = INT_MAX;
	target = INT_MIN;
	curr = to_search->top;
	while (curr)
	{
		if (n - curr->val < dif && n - curr->val > 0)
		{
			dif = n - curr->val;
			target = curr->val;
		}
		curr = curr->next;
	}
	return (target);
}

int	get_inmediate_upper(t_stack *to_search, int n)
{
	t_node	*current;
	int		closest_val;
	int		closest_diff;
	int		diff;

	if (!to_search || !to_search->top)
		return (INT_MIN);
	current = to_search->top;
	closest_val = INT_MIN;
	closest_diff = INT_MAX;
	if (is_biggest(to_search, n))
		return (INT_MAX);
	while (current)
	{
		diff = current->val - n;
		if (diff > 0 && diff < closest_diff)
		{
			closest_diff = diff;
			closest_val = current->val;
		}
		current = current->next;
	}
	return (closest_val);
}

int	get_target(t_stack *to_search, int n, int u_or_l)
{
	if (is_biggest(to_search, n) || is_smallest(to_search, n))
		return (get_biggest(to_search));
	else if (u_or_l)
		return (get_inmediate_lower(to_search, n));
	else if (!u_or_l)
		return (get_inmediate_upper(to_search, n));
	else
		return (INT_MIN);
}
