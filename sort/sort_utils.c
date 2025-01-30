/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:59:56 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:13:56 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_depth(t_stack *from, int n)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = from->top;
	while (curr)
	{
		if (curr->val == n)
		{
			if (i <= from->size / 2)
				return (i);
			else
				return (i - from->size);
		}
		i++;
		curr = curr->next;
	}
	return (INT_MIN);
}

void	bring_to_top(t_stack *a, int target)
{
	int	depth;

	depth = get_depth(a, target);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(a);
			depth++;
		}
		if (depth > 0)
		{
			ra(a);
			depth--;
		}
	}
}

void	bring_min_to_top(t_stack *stack)
{
	int	min_val;

	if (!stack || !stack->top)
		return ;
	min_val = get_smallest(stack);
	bring_to_top(stack, min_val);
}

void	handle_largest_at_top(t_stack *a)
{
	if (a->top->next->val < a->top->next->next->val)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}
