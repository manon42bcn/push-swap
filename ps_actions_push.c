/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:00:17 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 15:00:20 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_push(t_meta_data *meta, char ab)
{
	t_stacks *tmp;

	if (ab == 'a' || ab == 's')
	{
		if (ft_list_size(meta->first_a) > 0)
		{
			tmp = meta->first_a;
			meta->first_a = tmp->next;
			tmp->next = meta->first_b;
			meta->first_b = tmp;
		}
	}
	else if (ab == 'b' || ab == 's')
	{
		if (ft_list_size(meta->first_b) > 0)
		{
			tmp = meta->first_b;
			meta->first_b = tmp->next;
			tmp->next = meta->first_a;
			meta->first_a = tmp;
		}
	}
}
