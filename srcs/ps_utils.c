/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* esta funcion no la he usado... antes de entregar debo revisar si hay funciones fantasma */

int	ft_absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	ft_pick_pivot(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}

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
	if (i != meta->size)
		return (0);
	return (1);
}

int	ft_check_solve_stack(t_meta_data *meta, char ab)
{
	int			prev;
	t_stacks	*stack;
	int			i;

	stack = ft_select_stack(meta, ab);
	prev = stack->value;
	i = 0;
	while (ab == 'a' && stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	while (ab == 'b' && stack)
	{
		if (prev < stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (i);
}

t_stacks	*ft_get_node_from_index(t_meta_data *meta, char ab, int index)
{
	int			i;
	t_stacks	*node;

	i = 0;
	node = ft_select_stack(meta, ab);
	while (++i < index)
		node = node->next;
	return (node);
}

int	ft_get_index_from_node(t_meta_data *meta, char ab, t_stacks *to_find)
{
	int			i;
	t_stacks	*node;

	i = 1;
	node = ft_select_stack(meta, ab);
	while (to_find != node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int 	ft_smaller_than_pivot(t_meta_data *meta, char ab, char se, int pivot)
{
	t_stacks	*node;
	int			pivot_value;
	int			rst;
	int			pivot_checked;

	pivot_value = ft_get_value_node(meta, pivot, ab);
	node = ft_select_stack(meta, ab);
	rst = 0;
	pivot_checked = 0;
	while (node)
	{
		if (node->value == pivot_value && se == 'e')
			pivot_checked = 1;
		if (node->value == pivot_value && se == 's')
			break ;
		if (node->value < pivot_value && se == 's')
			rst++;
		if (node->value < pivot_value && se == 'e' && pivot_checked == 1)
			rst++;
		node = node->next;
	}
	return (rst);
}
