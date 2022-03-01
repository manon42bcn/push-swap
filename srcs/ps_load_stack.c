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

#include "../inc/push_swap.h"

int ft_less_dispersion(void)
{
	return (0);
}

int ft_general_cases(t_meta_data *meta)
{
	int			middle_index;
	int			rst;

	middle_index = ft_middle_point(meta, 'a');
	meta->pivot = ft_get_node_from_index(meta, 'a', middle_index);
	rst = 0;
	if (ft_list_size(meta->first_a) == 0)
		return(ft_pulling_back_all_stack(meta));
	if (ft_list_size(meta->first_a) < 6)
		return (ft_small_cases(meta, 'A') +  ft_pulling_back_all_stack(meta));
	if (meta->first_a == meta->pivot)
		return (ft_do_push(meta, 'a') + ft_placing_at_b(meta, meta->first_b) + ft_general_cases(meta));
	while (meta->first_a != meta->pivot)
	{
		if (meta->first_a->value < meta->pivot->value)
			rst += ft_do_push(meta, 'a') + ft_placing_at_b(meta, meta->first_b);
		else
			rst += ft_do_rotate(meta, 'a');
	}
	return (rst + ft_general_cases(meta));
}

int ft_to_spin_value(t_meta_data *meta, t_stacks *to_insert)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;
	int			index;

	node = meta->first_b;
	if (node == NULL)
		return (0);
	value = to_insert->value;
	rst = ft_get_value_node(meta, ft_min_at_stack(meta, 'b'), 'b');
	i = 0;
	index = 0;
	while (node)
	{
		i++;
		if (node->value < value && node->value >= rst)
		{
			rst = node->value;
			index = i;
		}
		node = node->next;
	}
	return (index);
}

int ft_spin_to_placing_at_b(t_meta_data *meta, int position)
{
	int			size;
	int			rst;

	size = ft_list_size(meta->first_b);
	rst = 0;
	if (size < 2)
		return (0);
	if (position > size / 2)
	{
		while (position-- > 1)
			rst += ft_do_reverse_rotate(meta, 'b');
	}
	else
	{
		while (position-- > 1)
			rst += ft_do_rotate(meta, 'b');
	}
	return (rst);
}

/*
si quiero insistir en la estrategua spin puedo evaluar...

elegir pivote absoluto, ordenar en B a lo basto con la secuencia de pivotes y utilizar el spin mientras se vuelve a A
intentar ir pasando numeros que esten relativamente cercanos, para ahorrarnos movimientos de preparacion.
por ejemplo ir evaluando a donde caeria el siguiente nodo... 
*/

int ft_spin_and_place(t_meta_data *meta)
{
	int	position;
	int	rst;

	position = ft_to_spin_value(meta, meta->first_a);
	rst = 0;
	rst += ft_spin_to_placing_at_b(meta, position);
	rst += ft_do_push(meta, 'a');
	return (rst);
}

int ft_general_cases_spin(t_meta_data *meta)
{
	int			middle_index;
	int			rst;

	middle_index = ft_middle_point(meta, 'a');
	meta->pivot = ft_get_node_from_index(meta, 'a', middle_index);
	rst = 0;
	if (ft_list_size(meta->first_a) == 0)
		return(ft_pulling_back_all_stack(meta));
	if (ft_list_size(meta->first_a) < 6)
		return (ft_small_cases(meta, 'A') +  ft_pulling_back_all_stack(meta));
	if (meta->first_a == meta->pivot)
		return (ft_spin_and_place(meta));
	while (meta->first_a != meta->pivot)
	{
		if (meta->first_a->value < meta->pivot->value)
			rst += ft_spin_and_place(meta);
		else
			rst += ft_do_rotate(meta, 'a');
	}
	return (rst + ft_general_cases_spin(meta));
}

int main(int argc, char *argv[])
{
	t_stacks	*stack_a;
	t_meta_data	*meta;
	t_stacks	*node;
	//t_stacks	*node_b;

	meta = ft_meta_data_init();
	stack_a = ft_load_stack(argc, argv, meta);
	if (meta == NULL || stack_a == NULL)
		return (0);
	//ft_push_all_stack(meta);
	//ft_placing_at_b(meta, meta->first_b);
	//printf("moves %i\n", ft_general_cases_v_dos(meta));
	//ft_push_all_stack(meta);
	//ft_do_push(meta, 'b');
	//printf("%i donde iria\n", ft_to_spin_value(meta, meta->first_a));
	//printf("%i spin mover\n", ft_spin_to_placing_at_b(meta, ft_to_spin_value(meta, meta->first_a)));
	//printf("=================\n");
	//printf("moves %i\n", ft_placing_at_b(meta, meta->first_b));
	printf("moves %i\n", ft_general_cases_spin(meta));
	//printf("moves %i\n", ft_general_cases(meta));
	//ft_select_cases(meta);
	//ft_push_all_stack(meta);
	node = meta->first_a;
	printf("stack_a\n");
	if (!node)
		printf("empty stack_a\n");
	int i;

	i = 1;
	while (node)
	{
		printf("%i\n", node->value);
		node = node->next;
		i++;
	}
	node = meta->first_b;
	printf("stack_b\n");
	if (!node)
		printf("empty stack_a\n");
	while (node)
	{
		printf("%i\n", node->value);
		node = node->next;
	}
	printf("%i solve\n", ft_check_solve(meta));
}
