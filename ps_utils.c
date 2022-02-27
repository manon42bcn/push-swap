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

#include "push_swap.h"

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

int	ft_solve_two_numbers(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		if (meta->first_a->value > meta->first_a->next->value)
			return (ft_do_swap(meta, 'a'));
		else
			return (0);
	}
	else
	{
		if (meta->first_b->value > meta->first_b->next->value)
			return (ft_do_swap(meta, 'b'));
		else
			return (0);
	}
}

int ft_absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int ft_get_value_node(t_meta_data *meta, int index, char ab)
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

int ft_pulling_back_all_stack(t_meta_data *meta)
{
	int	rst;

	rst = 0;
	while (meta->first_b != NULL)
	{
		ft_push_action(meta, 'b');
		write(1, "pb\n", 3);
		rst++;
	}
	return (rst);
}

int ft_push_all_stack(t_meta_data *meta)
{
	int	rst;

	rst = 0;
	while (meta->first_a != NULL)
	{
		ft_push_action(meta, 'a');
		write(1, "pa\n", 3);
		rst++;
	}
	return (rst);
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

int ft_solve_two_paralles(t_meta_data *meta)
{
	int	min_a;
	int	min_b;

	min_a = ft_min_at_stack(meta, 'a');
	min_b = ft_min_at_stack(meta, 'b');
	if (min_a == 1 	&& min_b == 2)
		return (0);
	if (min_a == 1 && min_b == 1)
		return (ft_do_swap(meta, 'b'));
	if (min_a == 2 && min_b == 1)
		return (ft_do_rotate(meta, 'r'));
	if (min_a == 2 && min_b == 2)
		return (ft_do_swap(meta, 'a'));
	return (0);
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
