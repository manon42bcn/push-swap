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

#include "push_swap.h"
#include "libft/ft_atoi.c"
#include "ps_stacks_utils.c"
#include "ps_actions_swap_rotate.c"
#include "ps_actions_push.c"

int main(int argc, char *argv[])
{
	t_stacks	*stack_a;
	t_meta_data	*meta;
	t_stacks	*node;
	t_stacks	*node_b;

	meta = ft_meta_data_init();
	stack_a = ft_load_stack(argc, argv, meta);
	if (meta == NULL || stack_a == NULL)
		return (0);
	ft_rotate_a(meta, 'a');
	node = meta->first_a;
	node_b = meta->first_b;
	printf("min %i max %i size %i\n", meta->min_val, meta->max_val, meta->size);
	while (node)
	{
		printf("%i\n", node->value);
		node = node->next;
		//node_b = node_b->next;
	}
	/*
	ft_push(meta, 'b');
	node = meta->first_a;
	while (node)
	{
		printf("%i\n", node->value);
		node = node->next;
	}
	printf("%i fnc size\n", ft_list_size(meta->first_a));
	*/
}
