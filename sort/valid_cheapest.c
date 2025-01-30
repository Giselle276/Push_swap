/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:17:06 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:14:52 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_combined_moves(int f_depth, int target_depth)
{
	if ((f_depth > 0 && target_depth > 0) || (f_depth < 0 && target_depth < 0))
		return (ft_max(ft_abs(f_depth), ft_abs(target_depth)));
	return (ft_abs(f_depth) + ft_abs(target_depth));
}

int	get_combined_moves(t_stack *from, t_stack *to, int val)
{
	int	f_depth;
	int	target;
	int	target_depth;

	f_depth = get_depth(from, val);
	target = get_target(to, val, 1);
	target_depth = get_depth(to, target);
	return (calculate_combined_moves(f_depth, target_depth));
}

void	update_cheapest(int *curr_steps, int combined_moves, int *cheapest_val,
			int val)
{
	if (combined_moves < *curr_steps)
	{
		*curr_steps = combined_moves;
		*cheapest_val = val;
	}
}

int	valid_cheapest(t_stack *from, t_stack *to)
{
	t_node	*curr;
	int		curr_steps;
	int		cheapest_val;
	int		combined_moves;

	curr = from->top;
	curr_steps = INT_MAX;
	cheapest_val = INT_MIN;
	while (curr)
	{
		combined_moves = get_combined_moves(from, to, curr->val);
		update_cheapest(&curr_steps, combined_moves, &cheapest_val, curr->val);
		curr = curr->next;
	}
	return (cheapest_val);
}
