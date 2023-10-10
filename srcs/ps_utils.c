/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Pushes all elements from stack 'b' to stack 'a'.
 * 
 * This function recursively pushes all elements from stack 'b' to stack
 * 'a' until stack 'b' is empty.
 * 
 * @param meta Metadata structure containing the state of the stacks.
 * 
 * @return Returns the number of push operations performed.
 */
int	ft_pulling_back_all_stack(t_meta_data *meta)
{
	if (meta->first_b == NULL)
		return (0);
	else
		return (ft_do_push(meta, 'b') + ft_pulling_back_all_stack(meta));
}

/**
 * @brief Computes the absolute value of an integer.
 * 
 * @param n Integer whose absolute value needs to be computed.
 * 
 * @return Returns the absolute value of the given integer.
 */
int	ft_absolute(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/**
 * @brief Calculates the number of elements in a linked list starting 
 * from the given node.
 * 
 * @param first_node Pointer to the first node of the linked list.
 * 
 * @return Returns the number of elements in the linked list.
 */
int	ft_list_size(t_stacks *first_node)
{
	t_stacks	*node;
	int			i;

	node = first_node;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

/**
 * @brief Selects a stack (either 'a' or 'b') based on the given identifier.
 * 
 * @param meta Metadata structure containing the state of the stacks.
 * @param ab Character identifier for the stack
 * ('a' for stack 'a', 'b' for stack 'b').
 * 
 * @return Returns a pointer to the first node of the selected stack.
 */
t_stacks	*ft_select_stack(t_meta_data *meta, char ab)
{
	t_stacks	*stack;

	if (ab == 'a')
		stack = meta->first_a;
	else
		stack = meta->first_b;
	return (stack);
}
