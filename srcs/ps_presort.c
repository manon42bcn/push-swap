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

int 	ft_smaller_than_pivot(t_meta_data *meta, char ab, char se, t_stacks *pivot)
{
	t_stacks	*node;
	int			rst;
	int			pivot_checked;

	node = ft_select_stack(meta, ab);
	rst = 0;
	pivot_checked = 0;
	while (node)
	{
		if (node->value == pivot->value && se == 'e')
			pivot_checked = 1;
		if (node->value == pivot->value && se == 's')
			break ;
		if (node->value < pivot->value && se == 's')
			rst++;
		if (node->value < pivot->value && se == 'e' && pivot_checked == 1)
			rst++;
		node = node->next;
	}
	return (rst);
}

t_stacks	*ft_select_pivot(t_meta_data *meta)
{
	t_stacks	*node;
	t_stacks	*hold;
	int			targets_hold;
	int			targets;

	node = ft_get_node_from_index(meta, 'a', ft_middle_point(meta, 'a'));
	targets = ft_smaller_than_pivot(meta, 'a', 's', node);
	hold = node;
	targets_hold = targets;
	if (ft_list_size(meta->first_a) > 25 && targets < 20)
	{
		while (node && targets_hold < 20)
		{
			node = ft_get_node_from_index(meta, 'a', ft_find_next(meta, 'a', ft_get_index_from_node(meta, 'a', node)));
			targets = ft_smaller_than_pivot(meta, 'a', 's', node);
			if (targets > targets_hold)
			{
				targets_hold = targets;
				hold = node;
			}
			node = node->next;
			printf("%i value %i targets\n", hold->value, targets_hold);
		}
		return (hold);
	}
	else if (ft_list_size(meta->first_a) > 25 && targets > 20)
	{
		while (node && targets_hold > 20)
		{
			node = ft_get_node_from_index(meta, 'a', ft_find_prev(meta, 'a', ft_get_index_from_node(meta, 'a', node)));
			targets = ft_smaller_than_pivot(meta, 'a', 's', node);
			if (targets < targets_hold && targets > 20)
			{
				targets_hold = targets;
				hold = node;
			}
			node = node->next;
			printf("%i value %i targets\n", hold->value, targets_hold);
		}
		return (hold);
	}
	return (ft_get_node_from_index(meta, 'a', ft_middle_point(meta, 'a')));
	/*
	t_stacks	*node;
	int			i;
	int			index;

	i = 0;
	node = ft_get_node_from_index(meta, 'a', ft_min_at_stack(meta, 'a'));
	if (meta->first_a->value == node->value && ft_list_size(meta->first_a) > 50)
	{
		while (i < 20)
		{
			index = ft_get_index_from_node(meta, 'a', node);
			node = ft_get_node_from_index(meta, 'a', ft_find_next(meta, 'a', index));
			i++;
		}
		return (node);
	}
	*/
}

int	*ft_next_distance(t_meta_data *meta, int *lower_upper_size)
{
	t_stacks	*node;

	node = meta->first_a->next;
	lower_upper_size[0] = 0;
	lower_upper_size[1] = 0;
	lower_upper_size[2] = 1;
	while (node)
	{
		lower_upper_size[2]++;
		if (node->value < meta->pivot->value && lower_upper_size[1] == 0)
			lower_upper_size[1] = lower_upper_size[2];
		if (node->value < meta->pivot->value)
			lower_upper_size[0] = lower_upper_size[2];
		node = node->next;
	}
	return (&lower_upper_size[0]);
}

int ft_next_to_send(t_meta_data *meta)
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
			rst += ft_do_reverse_rotate(meta, 'a');
	}
	else
		while (lower_upper_size[1]-- >= 1)
			rst += ft_do_rotate(meta, 'a');
	free(lower_upper_size);
	return (rst);
}

int ft_place_at_presort(t_meta_data *meta)
{
	t_stacks	*pivot_tmp;
	t_stacks	*node;

	pivot_tmp = ft_get_node_from_index(meta, 'b', ft_middle_point(meta, 'b'));
	node = meta->first_b;
	//if (ft_list_size(node) < 6)
	//	return (ft_small_cases(meta, 'B')); 
	//esta condicion resulta util en pilas grandes, en pequenas no tanto... la segunda tambien
	//if (node->value < pivot_tmp->value && meta->first_a->value < meta->pivot->value)
	//	return (ft_do_rotate(meta, 'r'));
	if (node->value < pivot_tmp->value)
	{
		return (ft_do_rotate(meta, 'b'));
	}
	else
		return (0);
}

int ft_presort_at_b(t_meta_data *meta)
{
	if (meta->first_a == NULL)
		return (0);
	if (ft_list_size(meta->first_a) < 6)
		return (ft_small_cases(meta, 'A'));
	if (meta->pivot == NULL)
	{
		meta->pivot = ft_select_pivot(meta); //ft_get_node_from_index(meta, 'a', ft_middle_point(meta, 'a'));
	}
	if (ft_min_at_stack(meta, 'a') == ft_get_index_from_node(meta, 'a', meta->pivot))
	{
		meta->pivot = NULL;
		return (ft_presort_at_b(meta));
	}
	if (meta->first_a->value < meta->pivot->value)
		return (ft_do_push(meta, 'a') + ft_place_at_presort(meta) + ft_presort_at_b(meta));
	if (meta->first_a->value >= meta->pivot->value)
		return (ft_next_to_send(meta) + ft_presort_at_b(meta));
	return (0);
}
