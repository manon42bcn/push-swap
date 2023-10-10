/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:30 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/26 16:40:36 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Executes the 'push' action and optionally prints the action.
 *
 * Based on the specified stack (A or B), pushes an element from one stack 
 * to the other and prints the executed action to the standard output.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Character indicating which stack to push from.
 * 
 * @return Returns 1 if the action was executed, 0 otherwise.
 */
int	ft_do_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("pb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("pa", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the 'rotate' action and optionally prints the action.
 *
 * Based on the specified stack (A, B, or both), rotates the elements 
 * and prints the executed action to the standard output.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Character indicating which stack to perform the rotation on.
 * 
 * @return Returns 1 if the action was executed, 0 otherwise.
 */
int	ft_do_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("ra", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rr", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the 'reverse rotate' action and optionally prints the action.
 *
 * Based on the specified stack (A, B, or both), performs the reverse rotation 
 * of elements and prints the executed action to the standard output.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Character indicating which stack to perform the reverse rotation on.
 * 
 * @return Returns 1 if the action was executed, 0 otherwise.
 */
int	ft_do_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("rra", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rrb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rrr", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the 'swap' action and optionally prints the action.
 *
 * Based on the specified stack (A, B, or both), swaps the top elements 
 * and prints the executed action to the standard output.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Character indicating which stack to perform the swap on.
 * 
 * @return Returns 1 if the action was executed, 0 otherwise.
 */
int	ft_do_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("sa", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("sb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("ss", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

/**
 * @brief Executes a specific action a set number of times.
 *
 * The specified action is executed 'i' times on the chosen stack.
 * 
 * @param meta Metadata structure containing stack information.
 * @param i The number of times to execute the action.
 * @param ab Character indicating which stack the action applies to.
 * @param act The function pointer to the action to be executed.
 * 
 * @return Returns the sum of the results of the executed actions.
 */
int	ft_do_while(t_meta_data *meta, int i, char ab,
	int (*act)(t_meta_data *, char))
{
	int	rst;

	rst = 0;
	while (i-- > 0)
		rst += act(meta, ab);
	return (rst);
}
