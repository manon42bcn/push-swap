/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:28:39 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_check_solve(t_meta_data *meta)
{
	int			i;
	int			prev;
	t_stacks	*stack;

	i = 0;
	if (meta->first_b != NULL)
		return (0);
	stack = meta->first_a;
	prev = stack->value;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}

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
