/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:04:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:06:48 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Frees the memory of the specified node and nullifies its next pointer.
 *
 * @param node The node to be deleted.
 */
static void	ft_delete_node(t_stacks *node)
{
	if (node)
	{
		node->next = NULL;
		free (node);
	}
}

/**
 * @brief Recursively frees all nodes starting from the provided node.
 *
 * Iterates through the linked list and deletes each node using
 * the ft_delete_node function.
 *
 * @param node The first node of the list to be cleared.
 */
static void	ft_clear_nodes(t_stacks *node)
{
	t_stacks	*tmp;

	while (node)
	{
		tmp = node->next;
		ft_delete_node(node);
		node = tmp;
	}
}

/**
 * @brief Clears the stack metadata and nullifies the head pointers.
 *
 * Resets the head pointers of both stacks to NULL and frees the
 * memory allocated to the meta structure.
 *
 * @param meta Pointer to the metadata structure.
 */
static void	ft_clear_stack(t_meta_data *meta)
{
	if (meta)
	{
		meta->first_a = NULL;
		meta->first_b = NULL;
		free (meta);
	}
}

/**
 * @brief Frees all strings within a split array and then the array itself.
 *
 * Iterates through the split array, freeing each string, then
 * frees the entire array.
 *
 * @param split Pointer to the string array.
 * @return Returns 0 after freeing the split.
 */
int	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (split[0])
	{
		while (i-- > 0)
			free (split[i]);
		i++;
	}
	free (split);
	return (0);
}

/**
 * @brief Clears all nodes of both stacks and then the metadata.
 *
 * Calls helper functions to clear individual stack nodes and
 * then the meta structure.
 *
 * @param meta Pointer to the metadata structure.
 * @return Returns 0 after clearing all structures.
 */
int	ft_clear_all(t_meta_data *meta)
{
	if (meta)
	{
		ft_clear_nodes(meta->first_a);
		ft_clear_nodes(meta->first_b);
		ft_clear_stack(meta);
	}
	return (0);
}
