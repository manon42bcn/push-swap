/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sml_do_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:38:50 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/03 14:53:42 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_do_sml_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'a');
	
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_do_sml_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');

		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_do_sml_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		return (1);
	}
	return (0);
}

int	ft_do_sml_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		return (1);
	}
	return (0);
}
