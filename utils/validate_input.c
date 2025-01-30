/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:58:24 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:15:17 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_single_input(char *input)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(input, ' ');
	if (!numbers)
		return (0);
	while (numbers[i])
	{
		if (!is_valid_input(numbers[i]) || !is_within_int_range(numbers[i]))
			return (ft_free_split(numbers), 0);
		i++;
	}
	ft_free_split(numbers);
	return (1);
}

int	validate_multiple_inputs(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_input(argv[i]) || !is_within_int_range(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char *argv[])
{
	if (argc == 2)
		return (validate_single_input(argv[1]));
	return (validate_multiple_inputs(argc, argv));
}
