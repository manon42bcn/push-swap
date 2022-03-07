/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sml_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:11:18 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 14:54:56 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_sml_general_solve(t_meta_data *meta)
{
	int	rst;

	rst = 0;
	rst += ft_sml_presort_at_b(meta);
	rst += ft_sml_spin_sort_at_a(meta);
	meta->moves = rst;
	return (rst);
}

int ft_solver_simulator(t_meta_data *meta)
{
	t_meta_data	*copy;
	t_stacks	*node;
	int			target;
	int			sim;

	node = meta->first_a;
	copy = ft_copy_stacks(meta);
	target = ft_sml_general_solve(copy);
	ft_clear_all(copy);
	printf ("%i old target\n", target);
	while (node)
	{
		copy = ft_copy_stacks(meta);
		copy->pivot = ft_get_node_from_value(copy, 'a', node->value);
		sim = ft_sml_general_solve(copy);
		if (sim < target)
		{
			meta->pivot = node; 
			target = sim;
			printf("%i new target\n", sim);
		}
		ft_clear_all(copy);
		node = node->next;
	}
	return (target);
}