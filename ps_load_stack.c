/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_load_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:22:21 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/24 23:22:27 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_atoi.c"
#include "ps_stacks_utils.c"

int ft_check_stack(t_meta_data *meta, int num)
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
				return (0)
			node = node->next;
		}
		return (1);
	}
}

t_stacks *ft_create_elem(int value, t_meta_data *meta)
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

t_stacks *ft_load_stack(int argc, char *argv[], t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;
	t_stacks	*first;

	i = 0;
	while (i < argc && argv[i])
	{
		num = ft_atoi(argv[i]);
		if (meta->first_a == NULL)
		{
			stack = ft_create_elem(num, meta);
			if (stack == NULL)
				return (NULL);		
		}
		else
		{
			stack->next = ft_create_elem(num, meta);
			stack = stack->next;
			if (stack == NULL)
				return (NULL);
		}
	}
	return (meta->first_a);
}

int main(int argc, char *argv[])
{
	t_meta_data	*meta;

	meta = ft_meta_data_ini();
	if (meta == NULL)
		return (NULL);

}