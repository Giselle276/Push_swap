/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:32:54 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:14:10 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->top->val > stack->top->next->val)
		ra(stack);
}

void	handle_smallest_in_middle(t_stack *a)
{
	sa(a);
	ra(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->val;
	second = a->top->next->val;
	third = a->top->next->next->val;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && first > third)
		handle_largest_at_top(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
		handle_smallest_in_middle(a);
}

void	push_back(t_stack *b, t_stack *a)
{
	t_node	*curr;
	int		target;

	curr = b->top;
	while (curr)
	{
		if (b->top == NULL)
			break ;
		curr = b->top;
		target = get_inmediate_upper(a, curr->val);
		if (target == INT_MAX)
			target = get_smallest(a);
		bring_to_top(a, target);
		pa(a, b);
		curr = curr->next;
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	num;

	num = INT_MIN;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3)
	{
		num = valid_cheapest(a, b);
		push_cheapest(a, b, num);
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		bring_min_to_top(a);
	}
	return ;
}
