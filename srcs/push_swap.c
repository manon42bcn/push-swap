/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:22:21 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 17:47:39 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_process_list(int argc, char *argv[])
{
	t_meta_data	*meta;

	meta = ft_meta_data_init();
	if (ft_load_stack(argc, argv, meta) == 0)
		return (ft_clear_all(meta));
	if (ft_check_solve(meta) == 1)
		return (ft_clear_all(meta) + 1);
	ft_find_best_pivot(meta);
	if (ft_get_sub_stack_limits(meta) == 0)
		return (ft_clear_all(meta));
	if (ft_select_cases(meta) == 0)
		return (ft_clear_all(meta));
	ft_clear_all(meta);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (ft_process_list(argc, argv) == 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	return (0);
}
