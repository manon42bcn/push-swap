/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ft_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:07:56 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 12:08:00 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stacks	*ft_create_elem_pivot(int value, t_meta_data *meta_pivot)
{
	t_stacks	*node;
	t_stacks	*tmp;

	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta_pivot->first_a == NULL)
		meta_pivot->first_a = node;
	else
	{
		tmp = meta_pivot->first_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	meta_pivot->size++;
	return (node);
}

t_stacks	*ft_create_elem_sim(int value, t_meta_data *meta, char ab)
{
	t_stacks	*node;

	if (ab == 'a')
		return (ft_create_elem(value, meta));
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta->first_b == NULL)
		meta->first_b = node;
	return (node);
}

void	ft_copy_nodes(t_meta_data *meta, t_meta_data *copy, char ab)
{
	t_stacks	*node;
	t_stacks	*node_copy;
	t_stacks	*stack;

	node = ft_select_stack(meta, ab);
	node_copy = ft_select_stack(copy, ab);
	while (node)
	{
		if (node_copy == NULL)
		{
			stack = ft_create_elem_sim(node->value, copy, ab);
			if (stack == NULL)
				return ;
		}
		else
		{
			stack->next = ft_create_elem_sim(node->value, copy, ab);
			stack = stack->next;
			if (stack == NULL)
				return ;
		}
		node = node->next;
	}
}

t_stacks	*ft_create_elem_a(int value, t_meta_data *meta)
{
	t_stacks	*node;

	if (ft_check_stack(meta, value) == 0)
		return (0);
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta->first_a == NULL)
	{
		meta->min_val = value;
		meta->max_val = value;
		meta->first_a = node;
	}
	else
	{
		if (value < meta->min_val)
			meta->min_val = value;
		else if (value > meta->max_val)
			meta->max_val = value;
	}
	meta->size++;
	return (node);
}

t_stacks	*ft_create_elem_copy(int value, t_meta_data *meta, char ab)
{
	t_stacks	*node;

	if (ab == 'a')
		return (ft_create_elem_a(value, meta));
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta->first_b == NULL)
		meta->first_b = node;
	return (node);
}

t_meta_data	*ft_copy_stacks_nodes(t_meta_data *meta, t_meta_data *dest, char ab)
{
	t_stacks	*stack;
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node)
	{
		if ((ab == 'a' && dest->first_a == NULL) || (ab == 'b' && dest->first_b == NULL))
		{
			stack = ft_create_elem_copy(node->value, dest, ab);
			if (stack == NULL)
				return (NULL);
		}
		else
		{
			stack->next = ft_create_elem_copy(node->value, dest, ab);
			stack = stack->next;
			if (stack == NULL)
				return (NULL);
		}
		node = node->next;
	}
	return (dest);
}

t_meta_data	*ft_copy_stacks(t_meta_data *meta)
{
	t_meta_data	*rst;

	rst = ft_meta_data_init();
	if (rst == NULL)
		return (NULL);
	rst = ft_copy_stacks_nodes(meta, rst, 'a');
	rst = ft_copy_stacks_nodes(meta, rst, 'b');
	return (rst);
}

int ft_build_pivots(t_meta_data *meta)
{
	t_meta_data	*meta_copy;
	t_meta_data	*pivots;

	pivots = ft_meta_data_init();
	if (pivots == NULL)
		return (0);
	meta_copy = ft_copy_stacks(meta);
	return (0);
}
