/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:47:04 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 17:47:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Evaluate if there are any errors in the metadata.
 *
 * This function checks for any errors in the metadata and based on the error
 * condition, prints appropriate results.
 *
 * @param meta Pointer to metadata.
 * @return Returns 0 if there's an error or the meta data indicates a solved
 * state; otherwise, it returns 1.
 */
static int	ft_evaluate_errors(t_meta_data *meta)
{
	if (meta->error == 1)
	{
		if (ft_check_error_solve() == 1)
			ft_print_results(1, meta);
		else
			ft_print_results(2, meta);
		return (0);
	}
	if (ft_check_solve(meta) == 1)
	{
		if (ft_check_error_solve() == 1)
			ft_print_results(1, meta);
		else
			ft_print_results(2, meta);
		return (0);
	}
	return (1);
}

/**
 * @brief The main function responsible for initializing and processing data.
 *
 * This function initializes metadata, processes the list and commands,
 * evaluates errors, and then checks if the meta data indicates a solved state.
 * Appropriate results are printed based on the checks.
 *
 * @param argc Count of arguments.
 * @param argv Array of argument strings.
 * @return Returns 0 in all cases after performing necessary operations.
 */
int	main(int argc, char *argv[])
{
	t_meta_data	*meta;

	if (argc == 1)
		return (0);
	meta = ft_meta_data_init();
	if (meta == NULL)
		return (0);
	ft_process_list(argc, argv, meta);
	if (ft_evaluate_errors(meta) == 0)
		return (ft_clear_all(meta));
	ft_process_commands(argc, meta);
	if (ft_check_solve(meta) == 0)
		ft_print_results(0, meta);
	else
		ft_print_results(1, meta);
	ft_clear_all(meta);
	return (0);
}
