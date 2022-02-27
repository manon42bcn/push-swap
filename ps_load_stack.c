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
#include "ps_actions.c"
#include "ps_do_actions.c"
#include "ps_utils.c"
#include "ps_cases_solve.c"

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
	ft_select_cases(meta);
	//ft_push_all_stack(meta);
	node = meta->first_a;
	printf("min %i max %i size %i\n", meta->min_val, meta->max_val, meta->size);
	printf("min next min index: %i y next min valor %i\n", ft_next_min(meta, meta->min_val, 'a'), ft_get_value_node(meta, ft_next_min(meta, meta->min_val, 'a'), 'a'));
	printf("max next index: %i y next max valor %i\n", ft_next_max(meta, meta->max_val, 'a'), ft_get_value_node(meta, ft_next_max(meta, meta->max_val, 'a'), 'a'));
	printf("stack_a\n");
	if (!node)
		printf("empty stack_a\n");
	while (node)
	{
		printf("%i\n", node->value);
		node = node->next;
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
