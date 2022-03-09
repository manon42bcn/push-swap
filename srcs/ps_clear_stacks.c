/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:04:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 11:04:29 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_delete_node(t_stacks *node)
{
	node->next = NULL;
	free (node);
}

static void	ft_clear_nodes(t_stacks *node)
{
	t_stacks	*tmp;

	while (node)
	{
		tmp = node->next;
		ft_delete_node(node);
		node = tmp;
	}
}

static void	ft_clear_stack(t_meta_data *meta)
{
	if (meta)
	{
		meta->first_a = NULL;
		meta->first_b = NULL;
		meta->pivot = NULL;
		free (meta);
	}
}

int	ft_clear_split(char **split)
{
	free(split);
	return (0);
}

int	ft_clear_all(t_meta_data *meta)
{
	ft_clear_nodes(meta->first_a);
	ft_clear_nodes(meta->first_b);
	ft_clear_nodes(meta->first_b);
	ft_clear_stack(meta);
	return (0);
}
