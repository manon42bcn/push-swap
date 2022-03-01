/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:56:37 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:56:40 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_pulling_back_all_stack(t_meta_data *meta)
{
	if (meta->first_b == NULL)
		return (0);
	else
		return(ft_do_push(meta, 'b') + ft_pulling_back_all_stack(meta));
}

int	ft_push_all_stack(t_meta_data *meta)
{
	if (meta->first_a == NULL)
		return (0);
	else
		return(ft_do_push(meta, 'a') + ft_push_all_stack(meta));
}

int	ft_solve_two_numbers(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		if (meta->first_a->value > meta->first_a->next->value)
			return (ft_do_swap(meta, 'a'));
		else
			return (0);
	}
	else
	{
		if (meta->first_b->value > meta->first_b->next->value)
			return (ft_do_swap(meta, 'b'));
		else
			return (0);
	}
}

int	ft_solve_two_paralles(t_meta_data *meta)
{
	int	min_a;
	int	min_b;

	min_a = ft_min_at_stack(meta, 'a');
	min_b = ft_min_at_stack(meta, 'b');
	if (min_a == 1 && min_b == 2)
		return (0);
	if (min_a == 1 && min_b == 1)
		return (ft_do_swap(meta, 'b'));
	if (min_a == 2 && min_b == 1)
		return (ft_do_rotate(meta, 'r'));
	if (min_a == 2 && min_b == 2)
		return (ft_do_swap(meta, 'a'));
	return (0);
}
