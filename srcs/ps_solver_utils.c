/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:48:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:48:15 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_check_solve(t_meta_data *meta)
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
	if (i != meta->size)
		return (0);
	return (1);
}

int ft_max_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			max;
	int			k;

	i = 1;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	k = 1;
	max = node->value;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			k = i;
		}
		i++;
		node = node->next;
	}
	return (k);
}

int ft_min_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			min;
	int			rst;

	i = 0;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	rst = 1;
	min = node->value;
	while (node)
	{
		i++;
		if (min > node->value)
		{
			min = node->value;
			rst = i;
		}
		node = node->next;
	}
	return (rst);
}
int ft_next_max(t_meta_data *meta, int max, char ab)
{
	t_stacks	*node;
	int			i;
	int			rst;
	int			k;

	node = ft_select_stack(meta, ab);
	rst = node->value;
	i = 1;
	k = 1;
	while (node)
	{
		if ((i == 2 && rst == max) || (node->value != max && node->value > rst))
		{
			rst = node->value;
			k = i;
		}
		node = node->next;
		i++;
	}
	return (k);
}

int ft_next_min(t_meta_data *meta, int min, char ab)
{
	t_stacks	*node;
	int			i;
	int			rst;
	int			k;

	node = ft_select_stack(meta, ab);
	rst = node->value;
	i = 1;
	k = 1;
	while (node)
	{
		if ((i == 2 && rst == min) || (node->value != min && node->value < rst))
		{
			rst = node->value;
			k = i;
		}
		node = node->next;
		i++;
	}
	return (k);
}
