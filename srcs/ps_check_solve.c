/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/04 16:29:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Checks if the stack A is sorted in ascending order.
 *
 * Verifies that stack A is properly sorted and that there are no elements 
 * in stack B. If both conditions are met, the function returns 1.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns 1 if stack A is sorted and stack B is empty, 0 otherwise.
 */
int	ft_check_solve(t_meta_data *meta)
{
	int			i;
	int			prev;
	t_stacks	*stack;

	i = 0;
	if (meta->first_b != NULL)
		return (0);
	stack = meta->first_a;
	prev = stack->value;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	if (i != meta->size)
		return (0);
	return (1);
}

/**
 * @brief Checks if the specified stack (A or B) is sorted.
 *
 * For stack A, the function checks if the elements are in ascending order. 
 * For stack B, it checks if the elements are in descending order. 
 * The function returns the number of elements in the checked stack.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Character indicating which stack (A or B) to check.
 * 
 * @return Returns the number of elements in the specified stack if sorted,
 *         0 otherwise.
 */
int	ft_check_solve_stack(t_meta_data *meta, char ab)
{
	int			prev;
	t_stacks	*stack;
	int			i;

	stack = ft_select_stack(meta, ab);
	prev = stack->value;
	i = 0;
	while (ab == 'a' && stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	while (ab == 'b' && stack)
	{
		if (prev < stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (i);
}
