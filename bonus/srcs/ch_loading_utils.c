/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_loading_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:26:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:12:21 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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

static t_stacks	*ft_create_elem(t_meta_data *meta, int value)
{
	t_stacks	*node;

	if (ft_check_input(meta, value) == 0)
		return (NULL);
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_meta_data	*ft_meta_data_init(void)
{
	t_meta_data	*rst;

	rst = (t_meta_data *)malloc(sizeof(t_meta_data));
	if (rst == NULL)
		return (NULL);
	rst->first_a = NULL;
	rst->first_b = NULL;
	return (rst);
}

int	ft_load_stack(char **input, int init, t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;
	t_stacks	*new;

	i = init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (ft_clear_all(meta));
		new = ft_create_elem(meta, ft_atoi(input[i]));
		if (new == NULL)
			return (ft_clear_all(meta));
		if (meta->first_a == NULL)
		{
			stack = new;
			meta->first_a = new;
		}
		else
		{
			stack->next = new;
			stack = stack->next;
		}
		i++;
	}
	return (1);
}
