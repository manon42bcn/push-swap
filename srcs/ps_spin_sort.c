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

static int ft_spin_to_place(t_meta_data *meta, int position, int size)
{
	if (position > size / 2)
	{
		position = (size - position) + 1;
		return(ft_do_while(meta, position, 'a', &ft_do_reverse_rotate));
	}
	else
		return(ft_do_while(meta, --position, 'a', &ft_do_rotate));
}

static int ft_to_spin_value_next(t_meta_data *meta, t_stacks *to_insert)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;
	int			index;

	node = meta->first_a;
	if (node == NULL)
		return (0);
	value = to_insert->value;
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

static int ft_to_spin_value_prev(t_meta_data *meta, t_stacks *to_insert)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;
	int			index;

	node = meta->first_a;
	if (node == NULL)
		return (0);
	value = to_insert->value;
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



static int	ft_spin(t_meta_data *meta, t_stacks *to_insert)
{
	int	index_prev;
	int index_next;
	int	size;

	size = ft_list_size(meta->first_a);
	index_next = ft_to_spin_value_next(meta, to_insert);
	index_prev = ft_to_spin_value_prev(meta, to_insert);

	if (meta->first_a == NULL)
		return (ft_do_push(meta, 'b'));
	if (index_prev == 0)
		return (ft_spin_to_place(meta, index_next, size) + ft_do_push(meta, 'b'));
	if (index_next == 0)
		return (ft_spin_to_place(meta, index_prev, size) + ft_do_push(meta, 'b'));
	if (index_next > index_prev)
		return (ft_spin_to_place(meta, index_prev, size) + ft_do_push(meta, 'b'));
	if (index_next <= index_prev)
		return (ft_spin_to_place(meta, index_next, size) + ft_do_push(meta, 'b'));
	return (0);
}

int ft_spin_sort_at_a(t_meta_data *meta)
{
	int rst;

	if (meta->first_b)
		return (ft_spin(meta, meta->first_b) + ft_spin_sort_at_a(meta));
	else
	{
		if (meta->first_a->value == meta->min_val)
			return (0);
		rst = ft_min_at_stack(meta, 'a');
		if (ft_max_at_stack(meta, 'a') >= ft_list_size(meta->first_a) / 2)
			return(ft_do_while(meta, ft_list_size(meta->first_a) - --rst, 'a', &ft_do_reverse_rotate));
		else
			return(ft_do_while(meta, --rst, 'a', &ft_do_rotate));
	}
}