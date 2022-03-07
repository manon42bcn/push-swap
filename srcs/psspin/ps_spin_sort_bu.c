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

static int	ft_spin_to_place(t_meta_data *meta, int position, int size, int sim)
{
	int	rst;

	rst = 0;
	if (position > size / 2)
	{
		position = (size - position) + 1;
		while (position-- > 0)
			rst += ft_do_reverse_rotate(meta, 'a', sim);
	}
	else
	{
		while (position-- > 1)
			rst += ft_do_rotate(meta, 'a', sim);
	}
	return (rst);
}

static int	ft_to_spin_value_next(t_meta_data *meta, t_stacks *to_insert)
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

static int	ft_to_spin_value_prev(t_meta_data *meta, t_stacks *to_insert)
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

static int	ft_spin_stack(t_meta_data *meta, t_stacks *to_insert, int sim)
{
	int	index;
	int	size;

	size = ft_list_size(meta->first_a);
	index = ft_to_spin_value_next(meta, to_insert);
	if (index > 0)
		return (ft_spin_to_place(meta, index, size, sim)
			+ ft_do_push(meta, 'b', sim));
	index = ft_to_spin_value_prev(meta, to_insert);
	if (index > 0)
		return (ft_spin_to_place(meta, index, size, sim)
			+ ft_do_push(meta, 'b', sim));
	return (0);
}

int	ft_spin_sort_at_a(t_meta_data *meta, int sim)
{
	int	rst;

	rst = 0;
	if (meta->first_b)
		return (ft_spin_stack(meta, meta->first_b, sim)
			+ ft_spin_sort_at_a(meta, sim));
	else
	{
		if (ft_max_at_stack(meta, 'a') >= ft_list_size(meta->first_a) / 2)
		{
			while (ft_min_at_stack(meta, 'a') > 1)
				rst += ft_do_reverse_rotate(meta, 'a', sim);
		}
		else
		{
			while (ft_min_at_stack(meta, 'a') > 1)
				rst += ft_do_rotate(meta, 'a', sim);
		}
		return (rst);
	}
}
