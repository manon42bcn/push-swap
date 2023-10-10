/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:30 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 22:48:37 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Executes the push action based on the specified stack.
 *
 * Pushes an element from one stack to the other. If pushing from stack 'a',
 * the top element of stack 'a' is pushed to stack 'b' and vice versa.
 *
 * @param meta Pointer to the metadata structure.
 * @param ab Indicates the source stack ('a' or 'b') for the push operation.
 * @return Returns 1 if the operation was successful, 0 otherwise.
 */
int	ft_do_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'b');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'a');
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the rotate action based on the specified stack.
 *
 * Rotates the stack, moving the top element to the bottom.
 *
 * @param meta Pointer to the metadata structure.
 * @param ab Indicates which stack ('a', 'b', or 'r' for both) to rotate.
 * @return Returns 1 if the operation was successful, 0 otherwise.
 */
int	ft_do_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the reverse rotate action based on the specified stack.
 *
 * Rotates the stack in reverse, moving the bottom element to the top.
 *
 * @param meta Pointer to the metadata structure.
 * @param ab Indicates which stack ('a', 'b', or 'r' for both) to reverse rotate.
 * @return Returns 1 if the operation was successful, 0 otherwise.
 */
int	ft_do_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

/**
 * @brief Executes the swap action based on the specified stack.
 *
 * Swaps the top two elements of the specified stack.
 *
 * @param meta Pointer to the metadata structure.
 * @param ab Indicates which stack ('a', 'b', or 'r' for both) to swap
 * elements in.
 * @return Returns 1 if the operation was successful, 0 otherwise.
 */
int	ft_do_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		return (1);
	}
	return (0);
}

/**
 * @brief Processes the input command and executes the corresponding action.
 *
 * Based on the input command line, this function maps the command to
 * its corresponding action (push, rotate, reverse rotate, swap) and
 * executes it.
 *
 * @param meta Pointer to the metadata structure.
 * @param line The input command string.
 * @return Returns 1 if the operation was successful, 0 otherwise.
 */
int	ft_get_command(t_meta_data *meta, char *line)
{
	if (ft_strlen(line) > 3)
		return (ft_do_reverse_rotate(meta, (char)(ft_strncmp(line, "rr", 3))));
	else
	{
		if (line[0] == 'p')
			return (ft_do_push(meta, (char)(ft_strncmp(line, "p", 2))));
		if (line[0] == 's')
			return (ft_do_swap(meta, (char)(ft_strncmp(line, "s", 2))));
		if (line[0] == 'r')
			return (ft_do_rotate(meta, (char)(ft_strncmp(line, "r", 2))));
	}
	return (0);
}
