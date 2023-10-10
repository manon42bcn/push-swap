/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nodes_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:32:56 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/04 16:32:59 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Retrieves a node from a stack based on the given index.
 *
 * Iterates through the selected stack until the specified index is reached.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Char indicating which stack to fetch from ('a' or 'b').
 * @param index Position of the desired node.
 * 
 * @return Returns the node at the specified index.
 */
t_stacks	*ft_get_node_from_index(t_meta_data *meta, char ab, int index)
{
	int			i;
	t_stacks	*node;

	i = 0;
	node = ft_select_stack(meta, ab);
	while (++i < index)
		node = node->next;
	return (node);
}

/**
 * @brief Retrieves the index of a specific node in the stack.
 *
 * Iterates through the selected stack to find the position of the given node.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Char indicating which stack to search in ('a' or 'b').
 * @param to_find Node whose index is to be found.
 * 
 * @return Returns the index of the node.
 */
int	ft_get_index_from_node(t_meta_data *meta, char ab, t_stacks *to_find)
{
	int			i;
	t_stacks	*node;

	i = 1;
	node = ft_select_stack(meta, ab);
	while (to_find != node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

/**
 * @brief Retrieves a node from a stack based on a specific value.
 *
 * Iterates through the selected stack until a node with the given value is found.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Char indicating which stack to fetch from ('a' or 'b').
 * @param value Value of the desired node.
 * 
 * @return Returns the node with the specified value, or NULL if not found.
 */
t_stacks	*ft_get_node_from_value(t_meta_data *meta, char ab, int value)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * @brief Retrieves the value of a node at a specific index in the stack.
 *
 * Iterates through the selected stack until the specified index is reached and
 * returns the value of that node.
 * 
 * @param meta Metadata structure containing stack information.
 * @param index Position of the desired node.
 * @param ab Char indicating which stack to fetch from ('a' or 'b').
 * 
 * @return Returns the value of the node at the specified index.
 */
int	ft_get_value_node(t_meta_data *meta, int index, char ab)
{
	int			i;
	t_stacks	*node;

	i = 0;
	node = ft_select_stack(meta, ab);
	while (++i < index)
		node = node->next;
	return (node->value);
}

/**
 * @brief Retrieves the index of a node with a specific value in the stack.
 *
 * Iterates through the selected stack to find the position of a node with the
 * given value.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Char indicating which stack to search in ('a' or 'b').
 * @param value Value to search for.
 * 
 * @return Returns the index of the node with the given value, or 0 if not found.
 */
int	ft_get_index_from_value(t_meta_data *meta, char ab, int value)
{
	t_stacks	*node;
	int			i;

	node = ft_select_stack(meta, ab);
	i = 1;
	while (node)
	{
		if (node->value == value)
			return (i);
		node = node->next;
		i++;
	}
	return (0);
}
