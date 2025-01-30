/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:36:25 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/01/26 01:14:40 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

int		check_errors(int argc, char *argv[]);
int		ft_abs(int n);
int		ft_atoi(const char *nptr);
void	ft_free_split(char **split);
int		ft_isdigit(int c);
int		ft_max(int a, int b);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_stack	*init_stack(void);
t_node	*new_node(int value);
void	push_stack(t_stack *stack, int value);
void	parse_init_stack(int argc, char **argv, t_stack *stack);
void	free_stack(t_stack *stack);
void	msg_error(void);
int		has_duplicates(t_stack *stack);
int		is_within_int_range(char *str);
int		ft_isspace(char c);
int		is_empty_string(char *str);
int		is_valid_input(char *str);
int		validate_single_input(char *input);
int		validate_multiple_inputs(int argc, char **argv);
int		validate_input(int argc, char **argv);
int		is_biggest(t_stack *to_search, int n);
int		is_smallest( t_stack *to_search, int n);
int		get_biggest(t_stack	*to_search);
int		get_smallest(t_stack *to_search);
void	rotate_from_to(t_stack *from, int *depth);
void	rotate_target_to(t_stack *to, int *depth);
void	rotate_both(t_stack *from, t_stack *to, int *n_depth,
			int *target_depth);
void	rotate_separately(t_stack *from, int *n_depth, t_stack *to,
			int *target_depth);
int		push_cheapest(t_stack *from, t_stack *to, int n);
int		is_sorted(t_stack *stack);
int		get_depth(t_stack *from, int n);
void	bring_to_top(t_stack *a, int target);
void	bring_min_to_top(t_stack *stack);
void	handle_largest_at_top(t_stack *a);
void	sort_two(t_stack *stack);
void	handle_smallest_in_middle(t_stack *a);
void	sort_three(t_stack *stack);
void	push_back(t_stack *b, t_stack *a);
void	sort(t_stack *a, t_stack *b);
int		get_inmediate_lower(t_stack *to_search, int n);
int		get_inmediate_upper(t_stack *to_search, int n);
int		get_target(t_stack *to_search, int n, int u_or_l);
int		calculate_combined_moves(int f_depth, int target_depth);
int		get_combined_moves(t_stack *from, t_stack *to, int val);
void	update_cheapest(int *curr_steps, int combined_moves, int *cheapest_val,
			int val);
int		valid_cheapest(t_stack *from, t_stack *to);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *a);

#endif
