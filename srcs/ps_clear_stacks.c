/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:04:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 11:04:29 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Deletes a single node from the stack.
 *
 * If the node exists, it sets its next pointer to NULL and frees its memory.
 * 
 * @param node The node from the stack to be deleted.
 */
void	ft_delete_node(t_stacks *node)
{
	if (node)
	{
		node->next = NULL;
		free (node);
	}
}

/**
 * @brief Clears all nodes in the stack.
 *
 * Iteratively deletes nodes from the stack until the entire stack is cleared.
 * 
 * @param node The starting node from which to begin the clearance.
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
 * @brief Clears the metadata structure.
 *
 * If the metadata structure exists, it frees its memory.
 * 
 * @param meta Metadata structure containing stack information.
 */
static void	ft_clear_stack(t_meta_data *meta)
{
	if (meta)
		free (meta);
}

/**
 * @brief Clears and frees the memory occupied by a split string array.
 *
 * Iteratively clears each string in the split array, then frees the entire array.
 * 
 * @param split The string array to be cleared.
 * 
 * @return Always returns 0.
 */
int	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		i++;
		while (i-- > 0)
			free (split[i]);
		i++;
		free (split);
	}
	return (0);
}

/**
 * @brief Clears all data structures associated with the swap project.
 *
 * Clears both stack A and B, the pivot, and then the metadata structure itself.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Always returns 0.
 */
int	ft_clear_all(t_meta_data *meta)
{
	if (meta)
	{
		ft_clear_nodes(meta->first_a);
		ft_clear_nodes(meta->first_b);
		ft_clear_nodes(meta->pivot);
		ft_clear_stack(meta);
	}
	return (0);
}
