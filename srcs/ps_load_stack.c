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
	printf("moves %i\n", ft_select_cases(meta));
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
