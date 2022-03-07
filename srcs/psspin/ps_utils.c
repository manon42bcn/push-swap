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

int 	ft_smaller_than_pivot(t_meta_data *meta, char ab, char se, t_stacks *pivot)
{
	t_stacks	*node;
	int			rst;
	int			pivot_checked;

	node = ft_select_stack(meta, ab);
	rst = 0;
	pivot_checked = 0;
	while (node)
	{
		if (node->value == pivot->value && se == 'e')
			pivot_checked = 1;
		if (node->value == pivot->value && se == 's')
			break ;
		if (node->value < pivot->value && se == 's')
			rst++;
		if (node->value < pivot->value && se == 'e' && pivot_checked == 1)
			rst++;
		node = node->next;
	}
	return (rst);
}
