/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_swap_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:21:59 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 14:58:30 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_action(t_meta_data *meta, char ab)
{
	int	value;

	if (ab == 'a' || ab == 's')
	{
		if (ft_list_size(meta->first_a) > 1)
		{
			value = meta->first_a->value;
			meta->first_a->value = meta->first_a->next->value;
			meta->first_a->next->value = value;
		}
	}
	if (ab == 'b' || ab == 's')
	{
		if (ft_list_size(meta->first_b) > 1)
		{
			value = meta->first_b->value;
			meta->first_b->value = meta->first_b->next->value;
			meta->first_b->next->value = value;
		}
	}
}

void	ft_rotate_a(t_meta_data *meta, char ab)
{
	t_stacks	*tmp;
	t_stacks	*node;
	t_stacks	*first;

	if (ab == 'a')
		first = meta->first_a;
	else
		first = meta->first_b;

	if (ft_list_size(first) > 1)
	{
		tmp = first;
		if (ab == 'a')
			meta->first_a = meta->first_a->next;
		else
			meta->first_b = meta->first_b->next;
		tmp->next = NULL;
		node = first;
		while (node->next != NULL)
			node = node->next;
		node->next = tmp;
	}
}

void	ft_rotate_b(t_meta_data *meta)
{
	t_stacks	*tmp;
	t_stacks	*node;

	if (ft_list_size(meta->first_b) > 1)
	{
		tmp = meta->first_b;
		meta->first_b = meta->first_b->next;
		tmp->next = NULL;
		node = meta->first_b;
		while (node->next != NULL)
			node = node->next;
		node->next = tmp;
	}
}

void	ft_reverse_rotate_a(t_meta_data *meta)
{
	t_stacks	*tmp;
	t_stacks	*node;

	if (ft_list_size(meta->first_a) > 1)
	{
		node = meta->first_a;
		while (node)
		{
			if ((node->next)->next == NULL)
			{
				tmp = node->next;
				node->next = NULL;
				break ;
			}
			node = node->next;
		}
		tmp->next = meta->first_a;
		meta->first_a = tmp;
	}
}

void	ft_reverse_rotate_b(t_meta_data *meta)
{
	t_stacks	*tmp;
	t_stacks	*node;

	if (ft_list_size(meta->first_b) > 1)
	{
		node = meta->first_b;
		while (node)
		{
			if ((node->next)->next == NULL)
			{
				tmp = node->next;
				node->next = NULL;
				break ;
			}
			node = node->next;
		}
		tmp->next = meta->first_b;
		meta->first_b = tmp;
	}
}
