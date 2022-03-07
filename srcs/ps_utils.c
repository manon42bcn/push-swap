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

int cuts = 10;

int ft_do_while(t_meta_data *meta, int i, char ab, int (*act)(t_meta_data *, char))
{
	int	rst;

	rst = 0;
	while (i-- > 0)
		rst += act(meta, ab);
	return (rst);
}

int ft_get_cuts(t_meta_data *meta)
{
	static int size = 0;

	if (size == 0)
		size = meta->size;
	size = size - cuts;
	//if (size < 21)
	//	return (size);
	//if (size > 20 && size < 51)
	//	return (15);
	return (cuts);

/*
	fix_size = ft_list_size(meta->first_a);
	if (fix_size < meta->size)
		fix_size--;
	if (fix_size > 0 && fix_size < 25)
		return (ft_list_size(meta->first_a));
	return (cuts);
	
	if (meta->size <= 100)
		return (16);
	else if (meta->size <= 500)
		return (45);
	return (10);
	*/
}

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

t_stacks	*ft_create_elem_sim(int value, t_meta_data *meta, char ab)
{
	t_stacks	*node;

	if (ab == 'a')
		return (ft_create_elem(value, meta));
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta->first_b == NULL)
		meta->first_b = node;
	return (node);
}

void	ft_copy_nodes(t_meta_data *meta, t_meta_data *copy, char ab)
{
	t_stacks	*node;
	t_stacks	*node_copy;
	t_stacks	*stack;

	node = ft_select_stack(meta, ab);
	node_copy = ft_select_stack(copy, ab);
	while (node)
	{
		if (node_copy == NULL)
		{
			stack = ft_create_elem_sim(node->value, copy, ab);
			if (stack == NULL)
				return ;
		}
		else
		{
			stack->next = ft_create_elem_sim(node->value, copy, ab);
			stack = stack->next;
			if (stack == NULL)
				return ;
		}
		node = node->next;
	}
}

t_stacks	*ft_create_elem_a(int value, t_meta_data *meta)
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

t_stacks	*ft_create_elem_copy(int value, t_meta_data *meta, char ab)
{
	t_stacks	*node;

	if (ab == 'a')
		return (ft_create_elem_a(value, meta));
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	if (meta->first_b == NULL)
		meta->first_b = node;
	return (node);
}

t_meta_data	*ft_copy_stacks_nodes(t_meta_data *meta, t_meta_data *dest)
{
	t_stacks	*stack;
	t_stacks	*node;

	node = meta->first_a;
	while (node)
	{
		if (dest->first_a == NULL)
		{
			stack = ft_create_elem_a(node->value, dest);
			if (stack == NULL)
				return (NULL);
		}
		else
		{
			stack->next = ft_create_elem_a(node->value, dest);
			stack = stack->next;
			if (stack == NULL)
				return (NULL);
		}
		node = node->next;
	}
	return (dest);
}

t_meta_data	*ft_copy_stacks(t_meta_data *meta)
{
	t_meta_data	*rst;

	rst = ft_meta_data_init();
	if (rst == NULL)
		return (NULL);
	rst = ft_copy_stacks_nodes(meta, rst);
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

void ft_testing_pivots(t_meta_data *meta)
{
	t_meta_data *copy;
	int min;
	int max;
	int sum;
	int min_cut;
	int max_cut;
	int i;

	i = 1;
	min = 0;
	max = 0;
	sum = 0;

	while (cuts < 50)
	{
		copy = ft_copy_stacks(meta);
		ft_get_sub_stack_limits(copy);
		copy->sim = 1;
		ft_select_cases(copy);
		if (copy->moves < min || min == 0)
		{
			min = copy->moves;
			min_cut = cuts;
		}
		if (copy->moves > max || max == 0)
		{
			max = copy->moves;
			max_cut = cuts;
		}
		sum += copy->moves;
		//printf("%i size, %i moves, %i cuts\n", copy->size, copy->moves, cuts);
		ft_clear_all(copy);
		cuts++;
		i++;
	}
	printf("%i size | %i min (%i)- %i max (%i) avr %i\n", meta->size, min, min_cut, max, max_cut, (sum / i));
}

int ft_check_numbers_at_list(t_meta_data *meta)
{
	t_stacks *node;
	t_stacks *pivots;

	node = meta->first_a;
	pivots = meta->pivot;

	//idea: hacer funcion que cuente cuantos numeros hay entre los pivotes...
	// dar prioridad a los numeros mas bajos de cada sub stack...
	// y practicar la mecanografia diariamente por favor...
	return (0);
}