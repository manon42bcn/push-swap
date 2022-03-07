/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:12:07 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/02 16:12:10 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_do_while(t_meta_data *meta, int i, char ab, int (*act)(t_meta_data *, char))
{
	int	rst;

	rst = 0;
	while (i-- > 0)
		rst += act(meta, ab);
	return (rst);
}

static int	ft_next_at_cut(t_meta_data *meta)
{
	t_stacks	*node;
	int			up_dw[2];
	int			size;
	int			i;

	node = meta->first_a;
	up_dw[0] = 0;
	up_dw[1] = 0;
	size = ft_list_size(meta->first_a);
	i = 1;
	while (node)
	{
		if (node->value < meta->pivot->value)
			up_dw[1] = i;
		if (node->value < meta->pivot->value && up_dw[0] == 0)
			up_dw[0] = i;
		node = node->next;
		i++;
	}
	if ((up_dw[0] - 1) > ((size - up_dw[1]) + 1))
		return (((size - up_dw[1]) + 1) * -1);
	else
		return (up_dw[0] - 1);
}

static int	ft_next_to_send(t_meta_data *meta)
{
	int			distance;
	int			rst;

	distance = ft_next_at_cut(meta);
	rst = 0;
	if (distance == 0)
		return (0);
	if (distance < 0)
	{
		distance = distance * -1;
		return (ft_do_while(meta, distance, 'a', &ft_do_reverse_rotate));
	}
	else
		return (ft_do_while(meta, distance, 'a', &ft_do_rotate));

}

int ft_spin_to_sort (t_meta_data *meta)
{
	if (meta)
		return (0);
	return (0);
}
int ft_presort_at_b(t_meta_data *meta)
{
	t_stacks	*pivot_stack;
	t_stacks	*tmp_pivot;

	if (meta->first_a == NULL)
		return (0);
	if (ft_list_size(meta->first_a) == 1)
		return (ft_spin_to_sort(meta)
		 		+ ft_do_push(meta, 'a'));
	pivot_stack = ft_get_node_from_value(meta, 'a', meta->pivot->value);
	if (ft_min_at_stack(meta, 'a') == ft_get_index_from_node(meta, 'a', pivot_stack))
	{
		tmp_pivot = meta->pivot;
		meta->pivot = tmp_pivot->next;
		free(tmp_pivot);
		return(ft_presort_at_b(meta));
	}
	if (meta->first_a->value < meta->pivot->value)
		return (ft_spin_to_sort(meta)
		 + ft_do_push(meta, 'a')
		 + ft_presort_at_b(meta));
	if (meta->first_a->value >= meta->pivot->value)
		return (ft_next_to_send(meta)
		+ ft_spin_to_sort(meta)
		+ ft_do_push(meta, 'a')
		+ ft_presort_at_b(meta));
	return (0);
}
