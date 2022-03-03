/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sml_presort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:42:31 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 14:42:34 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_sml_next_to_send(t_meta_data *meta)
{
	t_stacks	*node;
	int			*lower_upper_size;
	int			rst;

	node = meta->first_a->next;
	if (node == NULL)
		return (0);
	lower_upper_size = (int *)malloc(sizeof(int) * 3);
	if (lower_upper_size == NULL)
		return (0);
	lower_upper_size = ft_next_distance(meta, lower_upper_size);
	if (lower_upper_size[0] == 0 && lower_upper_size[1] == 0)
		return (0);
	rst = 0;
	if (lower_upper_size[1] - 1 > lower_upper_size[2] - lower_upper_size[0])
	{
		while (lower_upper_size[0]++ <= lower_upper_size[2])
			rst += ft_do_sml_reverse_rotate(meta, 'a');
	}
	else
		while (lower_upper_size[1]-- >= 1)
			rst += ft_do_sml_rotate(meta, 'a');
	free(lower_upper_size);
	return (rst);
}

int ft_sml_place_at_presort(t_meta_data *meta)
{
	t_stacks	*pivot_tmp;
	t_stacks	*node;

	pivot_tmp = ft_get_node_from_index(meta, 'b', ft_middle_point(meta, 'b'));
	node = meta->first_b;
	//if (ft_list_size(node) < 6)
	//	return (ft_small_cases(meta, 'B')); 
	//esta condicion resulta util en pilas grandes, en pequenas no tanto... la segunda tambien
	//if (node->value < pivot_tmp->value && meta->first_a->value < meta->pivot->value)
	//	return (ft_do_sml_rotate(meta, 'r'));
	if (node->value < pivot_tmp->value)
	{
		return (ft_do_sml_rotate(meta, 'b'));
	}
	else
		return (0);
}

int ft_sml_presort_at_b(t_meta_data *meta)
{
	if (meta->first_a == NULL)
		return (0);
	if (ft_list_size(meta->first_a) < 6)
		return (ft_small_cases(meta, 'A'));
	if (meta->pivot == NULL)
	{
		meta->pivot = ft_select_pivot(meta); //ft_get_node_from_index(meta, 'a', ft_middle_point(meta, 'a'));
		printf("%i pivotes..\n", meta->pivot->value);
	}
	if (ft_min_at_stack(meta, 'a') == ft_get_index_from_node(meta, 'a', meta->pivot))
	{
		meta->pivot = NULL;
		return (ft_sml_presort_at_b(meta));
	}
	if (meta->first_a->value < meta->pivot->value)
		return (ft_do_sml_push(meta, 'a') + ft_sml_place_at_presort(meta) + ft_sml_presort_at_b(meta));
	if (meta->first_a->value >= meta->pivot->value)
		return (ft_sml_next_to_send(meta) + ft_sml_presort_at_b(meta));
	return (0);
}
