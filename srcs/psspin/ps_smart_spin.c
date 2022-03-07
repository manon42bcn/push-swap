/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smart_spin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:24:07 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 21:24:14 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_smart_spin_place(t_meta_data *meta, t_stacks *to_insert)
{
	int	index;
	int	size;

	size = ft_list_size(meta->first_a);
	index = ft_to_spin_value_next(meta, to_insert);

	if (index > 0)
		return (ft_spin_to_next(meta, index, size) + ft_do_push(meta, 'b'));
	index = ft_to_spin_value_prev(meta, to_insert);
	if (index > 0)
		return (ft_spin_to_prev(meta, index, size) + ft_do_push(meta, 'b'));
	return (0);
}

int	ft_smart_spin(t_meta_data *meta)
{
	int	to_spin_next;
	int to_spin_prev;

}
