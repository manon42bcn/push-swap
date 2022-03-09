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

static int	ft_check_input(t_meta_data *meta, int num)
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

static int	ft_load_one_string(char *argv[], t_meta_data *meta)
{
	t_stacks	*stack;
	t_stacks	*new;
	char		**list;
	int			i;

	i = 0;
	list = ft_split(argv[1], ' ');
	if (list == NULL)
		return (0);
	while (list[i])
	{
		if (ft_send_to_atoi(list[i]) != 1)
			return (ft_clear_split(list) + ft_clear_all(meta));
		new = ft_create_elem(ft_atoi(&list[i][0]), meta);
		if (new == NULL)
			return (ft_clear_split(list));
		if (meta->first_a == NULL)
			stack = new;
		else
			stack->next = new;
		i++;
	}
	free(list);
	return (1);
}

t_meta_data	*ft_meta_data_init(void)
{
	t_meta_data	*rst;

	rst = (t_meta_data *)malloc(sizeof(t_meta_data));
	if (rst == NULL)
		return (NULL);
	rst->size = 0;
	rst->min_val = 0;
	rst->max_val = 0;
	rst->sim = 0;
	rst->cuts = 0;
	rst->first_a = NULL;
	rst->first_b = NULL;
	rst->pivot = NULL;
	return (rst);
}

t_stacks	*ft_create_elem(int value, t_meta_data *meta)
{
	t_stacks	*node;

	if (ft_check_input(meta, value) == 0)
		return (NULL);
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

int	ft_load_stack(int argc, char *argv[], t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;

	i = 1;
	if (argc == 2)
		return (ft_load_one_string(argv, meta));
	while (argc-- > 1 && argv[i])
	{
		if (ft_send_to_atoi(argv[i]) != 1)
			return (ft_clear_all(meta));
		if (meta->first_a == NULL)
		{
			stack = ft_create_elem(ft_atoi(argv[i]), meta);
			if (stack == NULL)
				return (ft_clear_all(meta));
		}
		else
		{
			stack->next = ft_create_elem(ft_atoi(argv[i]), meta);
			stack = stack->next;
			if (stack == NULL)
				return (ft_clear_all(meta));
		}
		i++;
	}
	return (1);
}
