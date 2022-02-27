/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:44:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:44:15 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

t_stacks	*ft_select_stack(t_meta_data *meta, char ab)
{
	t_stacks *stack;
	if (ab == 'a')
		stack = meta->first_a;
	else
		stack = meta->first_b;
	return (stack);
}

t_stacks	*ft_last_node(t_meta_data *meta, char ab)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_get_value_node(t_meta_data *meta, int index, char ab)
{
	int			i;
	t_stacks	*node;

	i = 0;
	if (ab == 'a')
		node = meta->first_a;
	else
		node = meta->first_b;
	while (++i < index)
		node = node->next;
	return (node->value);
}

int ft_value_position(t_meta_data *meta, int value, char ab)
{
	t_stacks	*node;
	int			i;

	i = 1;
	node = ft_select_stack(meta, ab);
	while (node && node->value != value)
	{
		node = node->next;
		i++;
	}
	return (i);
}
