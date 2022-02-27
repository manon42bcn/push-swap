/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_loading_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:26:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:42:44 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_meta_data	*ft_meta_data_init(void)
{
	t_meta_data	*rst;

	rst = (t_meta_data *)malloc(sizeof(t_meta_data));
	if (rst == NULL)
		return (NULL);
	rst->size = 0;
	rst->min_val = 0;
	rst->max_val = 0;
	rst->first_a = NULL;
	rst->first_b = NULL;
	return (rst);
}

int	ft_check_stack(t_meta_data *meta, int num)
{
	t_stacks	*node;

	if (meta->first_a == NULL)
		return (1);
	else
	{
		node = meta->first_a;
		while (node)
		{
			if (num == node->value)
				return (0);
			node = node->next;
		}
		return (1);
	}
}

t_stacks	*ft_create_elem(int value, t_meta_data *meta)
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

t_stacks	*ft_load_stack(int argc, char *argv[], t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;

	i = 1;
	if (meta == NULL)
		return (NULL);
	while (i < argc && argv[i])
	{
		if (meta->first_a == NULL)
		{
			stack = ft_create_elem(ft_atoi(argv[i]), meta);
			if (stack == NULL)
				return (NULL);
		}
		else
		{
			stack->next = ft_create_elem(ft_atoi(argv[i]), meta);
			stack = stack->next;
			if (stack == NULL)
				return (NULL);
		}
		i++;
	}
	return (meta->first_a);
}
