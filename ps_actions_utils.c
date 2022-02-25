/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:53:22 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 12:53:27 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stacks	*ft_rotate_list(t_stacks *begin)
{
	t_stacks	*node;
	t_stacks	*tmp;

	tmp = begin;
	tmp->next = NULL;
	node = begin->next;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	return (begin->next);
}
