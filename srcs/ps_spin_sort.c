/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_spin_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:02:28 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/02 16:02:32 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Finds the position of the smallest number that is greater than a
 * given value in stack 'a'.
 * 
 * This function is useful when we want to determine the position of the 
 * next larger value to 'value' in stack 'a'.
 * 
 * @param meta Metadata structure containing stack information.
 * @param value The value to compare against.
 * 
 * @return Returns the position of the smallest number that is greater than
 * 'value'. If no such value exists, returns 0.
 */
static int	ft_to_spin_value_next(t_meta_data *meta, int value)
{
	t_stacks	*node;
	int			rst;
	int			i;
	int			index;

	node = meta->first_a;
	if (node == NULL)
		return (0);
	rst = ft_get_value_node(meta, ft_max_at_stack(meta, 'a'), 'a');
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
 * @brief Determines the position of the largest number that is less than
 * a given value in stack 'a'.
 * 
 * This function is utilized to locate the position of the immediately
 * smaller value to 'value' in stack 'a'.
 * 
 * @param meta Metadata structure containing stack information.
 * @param value The number to compare with.
 * 
 * @return Returns the position of the largest number less than 'value'.
 * If no such number is present, it returns 0.
 */
static int	ft_to_spin_value_prev(t_meta_data *meta, int value)
{
	t_stacks	*node;
	int			rst;
	int			i;
	int			index;

	node = meta->first_a;
	if (node == NULL)
		return (0);
	rst = ft_get_value_node(meta, ft_min_at_stack(meta, 'a'), 'a');
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
 * @brief Adjusts the position of the top element of stack 'a' and then
 * pushes it to stack 'b'.
 * 
 * This function optimizes the rotation of stack 'a' so that the element 
 * which needs to be pushed to stack 'b' reaches the top with the least
 * number of rotations.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return The number of actions taken.
 */
static int	ft_spin(t_meta_data *meta)
{
	int	index;
	int	size;
	int	prepare;

	if (meta->first_a == NULL)
		return (ft_do_push(meta, 'b'));
	size = ft_list_size(meta->first_a);
	prepare = ft_prepare_spin(meta);
	index = ft_find_place(meta, meta->first_b->value);
	if (index < 0)
	{
		index = index * -1;
		return (prepare
			+ ft_do_while(meta, index, 'a', &ft_do_reverse_rotate)
			+ ft_do_push(meta, 'b'));
	}
	else
		return (prepare
			+ ft_do_while(meta, index, 'a', &ft_do_rotate)
			+ ft_do_push(meta, 'b'));
	return (0);
}

/**
 * @brief Calculates the optimal position for placing a given value
 * in stack 'a'.
 * 
 * If the value is to be placed closer to the start of the stack,
 * a positive index is returned. If it's closer to the end, a negative
 * index is returned.
 * 
 * @param meta Metadata structure containing stack information.
 * @param value The value for which position is to be found.
 * 
 * @return Returns the optimal position as an integer.
 */
int	ft_find_place(t_meta_data *meta, int value)
{
	int	index;
	int	size;

	size = ft_list_size(meta->first_a);
	index = ft_to_spin_value_next(meta, value);
	if (index == 0)
		index = ft_to_spin_value_prev(meta, value);
	if (index > size / 2)
		index = (size - index + 1) * -1;
	else
		--index;
	return (index);
}

/**
 * @brief Ensures that the elements of stack 'b' are correctly placed
 * on stack 'a'.
 * 
 * This function repeatedly calls the spin function until stack 'b' is empty.
 * After that, it ensures that stack 'a' is sorted in the right order.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return The number of actions executed.
 */
int	ft_spin_sort_at_a(t_meta_data *meta)
{
	int	rst;

	if (meta->first_b)
		return (ft_spin(meta) + ft_spin_sort_at_a(meta));
	else
	{
		if (meta->first_a->value == meta->min_val)
			return (0);
		rst = ft_min_at_stack(meta, 'a');
		if (ft_max_at_stack(meta, 'a') >= ft_list_size(meta->first_a) / 2)
			return (ft_do_while(meta, ft_list_size(meta->first_a)
					- --rst, 'a', &ft_do_reverse_rotate));
		else
			return (ft_do_while(meta, --rst, 'a', &ft_do_rotate));
	}
}
