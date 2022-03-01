/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cases_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:25:14 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 22:25:18 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_select_cases(t_meta_data *meta)
{
	if (meta->size <= 5)
		return (ft_small_cases(meta, 'a'));
	return (0);
}
