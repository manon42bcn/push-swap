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

void ft_print_stacks(t_meta_data *meta)
{
	t_stacks *node_a;
	t_stacks *node_b;

	node_a = meta->first_a;
	node_b = meta->first_b;
	printf("_MOVES_ %i\n", meta->moves);
	if (node_a || node_b)
		printf ("_STACK_A_ | _STACK_B_\n");
	while (node_a || node_b)
	{
		if (node_a)
			printf("%9i ", node_a->value);
		if (node_b)
			printf("| %9i", node_b->value);
		printf("\n");
		if (node_a)
			node_a = node_a->next;
		if (node_b)
			node_b = node_b->next;
		if (!node_a && !node_b)
			break;
	}
}

void ft_print_limits(t_meta_data *meta)
{
	t_stacks *node_a;

	node_a = meta->pivot;
	while (node_a)
	{
		printf("%9i\n", node_a->value);
		node_a = node_a->next;
	}
}

int 	ft_process_list(int argc, char *argv[])
{
	t_meta_data	*meta;

	meta = ft_meta_data_init();
	if (ft_load_stack(argc, argv, meta) == 0)
		return (0);
	//ft_print_stacks(meta);
	if (ft_check_solve(meta) == 1)
		return (1);
	ft_get_sub_stack_limits(meta);
	meta->sim = 1;
	if (ft_select_cases(meta) == 0)
		return (0);
	//ft_print_limits(meta);
	ft_print_stacks(meta);
	return (1);
}

int main(int argc, char *argv[])
{
	if (ft_process_list(argc, argv) == 0)
		write(1, "Error\n", 6);
	return (0);
}
