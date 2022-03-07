/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:30 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/26 16:40:36 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_do_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'a');
		if (meta->sim == 0)
			write(1, "pb\n", 3);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	ft_do_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');
		if (meta->sim == 0)
			write(1, "ra\n", 3);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "rb\n", 3);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

int	ft_do_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		if (meta->sim == 0)
			write(1, "rra\n", 4);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "rrb\n", 4);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}

int	ft_do_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		if (meta->sim == 0)
			write(1, "sa\n", 3);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "sb\n", 3);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	ft_pulling_back_all_stack(t_meta_data *meta)
{
	if (meta->first_b == NULL)
		return (0);
	else
		return(ft_do_push(meta, 'b') + ft_pulling_back_all_stack(meta));
}
