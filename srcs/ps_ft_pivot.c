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

t_meta_data	*ft_copy_stacks(t_meta_data *meta)
{
	t_stacks	*stack;
	t_stacks	*node;
	t_meta_data	*rst;

	rst = ft_meta_data_init();
	if (rst == NULL)
		return (NULL);
	node = meta->first_a;
	while (node)
	{
		if (rst->first_a == NULL)
		{
			stack = ft_create_elem(node->value, rst);
			if (stack == NULL)
				return (NULL);
		}
		else
		{
			stack->next = ft_create_elem(node->value, rst);
			stack = stack->next;
			if (stack == NULL)
				return (NULL);
		}
		node = node->next;
	}
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

int ft_solver_simulator(t_meta_data *meta)
{
	t_meta_data	*copy;
	int			moves;
	
	copy = ft_copy_stacks(meta);
	return (ft_select_cases(copy));
}


