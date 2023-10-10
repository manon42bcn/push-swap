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

/**
 * @brief Executes a general solution for sorting.
 *
 * Performs a preliminary sort on stack B and then a spin sort on stack A.
 * Stores the total number of moves in the metadata structure.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return The total number of moves required for the general solution.
 */
static int	ft_general_solve(t_meta_data *meta)
{
	int	rst;

	rst = 0;
	rst += ft_presort_at_b(meta);
	rst += ft_spin_sort_at_a(meta);
	meta->moves = rst;
	return (rst);
}

/**
 * @brief Selects the appropriate sorting strategy based on the stack size.
 *
 * If the size of the stack is less than or equal to 5, a specialized solution
 * for small stacks is used. Otherwise, a general solution is used.
 * 
 * @param meta Metadata structure containing stack information.
 * 
 * @return Returns the result of the selected sorting solution.
 */
int	ft_select_cases(t_meta_data *meta)
{
	if (meta->size <= 5)
		return (ft_small_cases(meta, 'a'));
	else
		return (ft_general_solve(meta));
	return (0);
}
