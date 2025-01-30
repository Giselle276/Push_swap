/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:36:03 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:15:25 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1 && is_empty_string(argv[1]))
		return (1);
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (!validate_input(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (check_errors(argc, argv))
		msg_error();
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		msg_error();
	parse_init_stack(argc, argv, stack_a);
	if (has_duplicates(stack_a))
		msg_error();
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
