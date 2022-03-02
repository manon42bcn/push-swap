/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_general_solve_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:07:13 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/28 22:07:19 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int 	ft_undo_rotate(t_meta_data *meta)
{
	if (ft_min_at_stack(meta, 'b') == ft_list_size(meta->first_b))
		return (0);
	return (ft_do_reverse_rotate(meta, 'b') + ft_undo_rotate(meta));
}

static int 	ft_undo_reverse_rotate(t_meta_data *meta)
{
	if (ft_min_at_stack(meta, 'b') == ft_list_size(meta->first_b))
		return (0);
	return (ft_do_rotate(meta, 'b') + ft_undo_rotate(meta));
}

int ft_double_rotate(t_meta_data *meta)
{
	if (meta->first_a != NULL)
	{
		if (meta->first_a->value > meta->pivot->value && meta->first_a->value != meta->pivot->value)
			return (ft_do_rotate(meta, 'r'));
	}
	return (ft_do_rotate(meta, 'b'));
}

int ft_placing_at_b(t_meta_data *meta, t_stacks *to_place)
{
	int			to_place_index;
	int			size;

	to_place_index = ft_get_index_from_node(meta, 'b', to_place);
	size = ft_list_size(meta->first_b);
	if (size < 2)
		return (0);
	if (ft_max_at_stack(meta, 'b') == to_place_index)
		return (0);
	if (ft_min_at_stack(meta, 'b') == to_place_index)
		return (ft_double_rotate(meta));
	if (to_place_index == 1 && ft_find_next(meta,'b', to_place_index) == size)
		return (ft_double_rotate(meta) + ft_undo_reverse_rotate(meta));
	if ((to_place_index + 1) == ft_find_prev(meta, 'b', to_place_index))
		return (ft_undo_rotate(meta));
	if (ft_find_next(meta, 'b', to_place_index) > size / 2)
		return (ft_do_reverse_rotate(meta, 'b') + ft_do_swap(meta, 'b') + ft_placing_at_b(meta, to_place));
	return (ft_do_swap(meta, 'b') + ft_double_rotate(meta) + ft_placing_at_b(meta, to_place));
}
