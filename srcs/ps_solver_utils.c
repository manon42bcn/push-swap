/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:48:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:48:15 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Finds the position of the maximum value in the given stack.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Indicates which stack to process ('a' or 'b').
 * 
 * @return Returns the position of the maximum value.
 */
int	ft_max_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			min;
	int			rst;

	i = 0;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	rst = 1;
	min = node->value;
	while (node)
	{
		i++;
		if (min < node->value)
		{
			min = node->value;
			rst = i;
		}
		node = node->next;
	}
	return (rst);
}

/**
 * @brief Finds the position of the minimum value in the given stack.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Indicates which stack to process ('a' or 'b').
 * 
 * @return Returns the position of the minimum value.
 */
int	ft_min_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			min;
	int			rst;

	i = 0;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	rst = 1;
	min = node->value;
	while (node)
	{
		i++;
		if (min > node->value)
		{
			min = node->value;
			rst = i;
		}
		node = node->next;
	}
	return (rst);
}

/**
 * @brief Finds the position of the next greater number than the one at 
 * the given index.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Indicates which stack to process ('a' or 'b').
 * @param index Index of the current number to check against.
 * 
 * @return Returns the position of the next greater number.
 */
int	ft_find_next(t_meta_data *meta, char ab, int index)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;

	node = ft_select_stack(meta, ab);
	value = ft_get_value_node(meta, index, ab);
	rst = ft_get_value_node(meta, ft_max_at_stack(meta, ab), ab);
	i = 0;
	index = 0;
	while (node)
	{
		i++;
		if (node->value > value && node->value <= rst)
		{
			rst = node->value;
			index = i;
		}
		node = node->next;
	}
	return (index);
}

/**
 * @brief Finds the position of the previous smaller number than the one 
 * at the given index.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Indicates which stack to process ('a' or 'b').
 * @param index Index of the current number to check against.
 * 
 * @return Returns the position of the previous smaller number.
 */
int	ft_find_prev(t_meta_data *meta, char ab, int index)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;

	node = ft_select_stack(meta, ab);
	value = ft_get_value_node(meta, index, ab);
	rst = ft_get_value_node(meta, ft_min_at_stack(meta, ab), ab);
	i = 0;
	index = 0;
	while (node)
	{
		i++;
		if (node->value < value && node->value >= rst)
		{
			rst = node->value;
			index = i;
		}
		node = node->next;
	}
	return (index);
}

/**
 * @brief Gets the last node in the given stack.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Indicates which stack to process ('a' or 'b').
 * 
 * @return Returns the pointer to the last node.
 */
t_stacks	*ft_last_node(t_meta_data *meta, char ab)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
