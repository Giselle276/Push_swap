/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:16:19 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:16:56 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_from_to(t_stack *from, int *depth)
{
	if (*depth > 0)
	{
		ra(from);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rra(from);
		(*depth)++;
	}
}

void	rotate_target_to(t_stack *to, int *depth)
{
	if (*depth > 0)
	{
		rb(to);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rrb(to);
		(*depth)++;
	}
}

void	rotate_both(t_stack *from, t_stack *to, int *n_depth, int *target_depth)
{
	if (*n_depth > 0 && *target_depth > 0)
	{
		rr(from, to);
		(*n_depth)--;
		(*target_depth)--;
	}
	else if (*n_depth < 0 && *target_depth < 0)
	{
		rrr(from, to);
		(*n_depth)++;
		(*target_depth)++;
	}
}

void	rotate_separately(t_stack *from, int *n_depth, t_stack *to,
			int *target_depth)
{
	rotate_from_to(from, n_depth);
	rotate_target_to(to, target_depth);
}

int	push_cheapest(t_stack *from, t_stack *to, int n)
{
	int	n_depth;
	int	target;
	int	target_depth;

	n_depth = get_depth(from, n);
	target = get_target(to, n, 1);
	target_depth = get_depth(to, target);
	while (n_depth != 0 || target_depth != 0)
	{
		if ((n_depth > 0 && target_depth > 0)
			|| (n_depth < 0 && target_depth < 0))
			rotate_both(from, to, &n_depth, &target_depth);
		else
			rotate_separately(from, &n_depth, to, &target_depth);
	}
	return (pb(from, to), 0);
}
