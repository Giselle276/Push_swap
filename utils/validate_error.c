/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:05:06 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/24 10:44:57 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_error(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*inner;

	current = stack->top;
	while (current != NULL)
	{
		inner = current->next;
		while (inner != NULL)
		{
			if (current->val == inner->val)
				return (1);
			inner = inner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_within_int_range(char *str)
{
	if (*str == '-')
	{
		if (ft_strlen(str) > 11 || (ft_strlen(str) == 11 && ft_strncmp(str,
					"-2147483648", 11) > 0))
			return (0);
	}
	else
	{
		if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 && ft_strncmp(str,
					"2147483647", 10) > 0))
			return (0);
	}
	return (1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
