/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:12:07 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/02 16:12:10 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @brief Determines the next index to cut in stack A.
 * 
 * Iterates through stack A and computes the number of moves required to
 * push the next value below the pivot value.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns the number of moves needed to access the next cut.
 */
static int	ft_next_at_cut(t_meta_data *meta)
{
	t_stacks	*node;
	int			up_dw[2];
	int			size;
	int			i;

	node = meta->first_a;
	up_dw[0] = 0;
	up_dw[1] = 0;
	size = ft_list_size(meta->first_a);
	i = 1;
	while (node)
	{
		if (node->value < meta->pivot->value)
			up_dw[1] = i;
		if (node->value < meta->pivot->value && up_dw[0] == 0)
			up_dw[0] = i;
		node = node->next;
		i++;
	}
	if ((up_dw[0] - 1) > ((size - up_dw[1]) + 1))
		return (((size - up_dw[1]) + 1) * -1);
	else
		return (up_dw[0] - 1);
}

/**
 * @brief Determines and performs the required rotations to send the next element.
 *
 * Computes the next rotation operation (either rotate or reverse rotate)
 * for the element to be pushed from stack A.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns the number of moves performed.
 */
static int	ft_next_to_send(t_meta_data *meta)
{
	int			distance;
	int			rst;

	distance = ft_next_at_cut(meta);
	rst = 0;
	if (distance == 0)
		return (0);
	if (distance < 0)
	{
		distance = distance * -1;
		return (ft_do_while(meta, distance, 'a', &ft_do_reverse_rotate));
	}
	else
		return (ft_do_while(meta, distance, 'a', &ft_do_rotate));
}

/**
 * @brief Determines the middle value of a given stack.
 *
 * Iterates through the selected stack to find the middle value.
 * 
 * @param meta Metadata structure containing stack information.
 * @param ab Char indicating which stack to fetch from ('a' or 'b').
 * 
 * @return Returns the index of the middle value.
 */
static int	ft_middle_point(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			stack_size;
	int			middle_index;
	int			i;
	int			node_index;

	node = ft_select_stack(meta, ab);
	stack_size = ft_list_size(node);
	if (stack_size == 0)
		return (0);
	middle_index = stack_size / 2;
	node_index = ft_min_at_stack(meta, ab);
	i = 1;
	while (i++ < middle_index)
		node_index = ft_find_next(meta, ab, node_index);
	return (node_index);
}

/**
 * @brief Performs the rotation required for stack B based on its size.
 *
 * Depending on the size of stack B, the function may decide to do a single
 * rotation on stack A, a single rotation on stack B, or no operation.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns the number of moves performed.
 */
static int	ft_spin_pivot_b(t_meta_data *meta)
{
	t_stacks	*pivot_b;
	int			middle;
	int			size;

	size = ft_list_size(meta->first_b);
	if (size < 3)
		return (0);
	if (size > 15)
	{
		middle = ft_middle_point(meta, 'b');
		pivot_b = ft_get_node_from_index(meta, 'b', middle);
		if (meta->first_b->value < pivot_b->value)
		{
			if (ft_next_at_cut(meta) > 0)
				return (ft_do_rotate(meta, 'r'));
			return (ft_do_rotate(meta, 'a'));
		}
	}
	return (0);
}

/**
 * @brief Performs the pre-sorting operations on stack B.
 *
 * Iterates through stack A to decide if values should be pushed to stack B.
 * Based on pivot values and current stack contents, different operations
 * might be performed to prepare stack B for further sorting.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns the number of moves performed.
 */
int	ft_presort_at_b(t_meta_data *meta)
{
	t_stacks	*pivot_stack;
	t_stacks	*tmp_pivot;

	if (ft_list_size(meta->first_a) == 1 || meta->first_a == NULL)
		return (0);
	pivot_stack = ft_get_node_from_value(meta, 'a', meta->pivot->value);
	if (ft_min_at_stack(meta, 'a')
		== ft_get_index_from_node(meta, 'a', pivot_stack))
	{
		tmp_pivot = meta->pivot;
		meta->pivot = tmp_pivot->next;
		ft_delete_node(tmp_pivot);
		return (ft_presort_at_b(meta));
	}
	if (meta->first_a->value < meta->pivot->value)
		return (ft_do_push(meta, 'a')
			+ ft_spin_pivot_b(meta)
			+ ft_presort_at_b(meta));
	if (meta->first_a->value >= meta->pivot->value)
		return (ft_next_to_send(meta)
			+ ft_do_push(meta, 'a')
			+ ft_spin_pivot_b(meta)
			+ ft_presort_at_b(meta));
	return (0);
}
