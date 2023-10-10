/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_process_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:09:02 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/10 16:09:10 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Load the list of numbers into the stack.
 *
 * If there's only one argument, it assumes the numbers are space-separated
 * inside that single argument and splits it accordingly. Otherwise, it
 * takes numbers from the command line arguments directly.
 *
 * @param argc Argument count from the main function.
 * @param argv Argument values from the main function.
 * @param meta A pointer to the meta_data structure.
 * @return Returns 1 if the loading was successful, 0 otherwise.
 */
static int	ft_loader_select(int argc, char *argv[], t_meta_data *meta)
{
	char	**list;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
			return (0);
		if (ft_check_input_limits(list, meta) == 0)
			return (ft_clear_split(list));
		if (ft_load_stack(list, meta) == 0)
			return (ft_clear_split(list));
		ft_clear_split(list);
		return (1);
	}
	else
	{
		meta->init = 1;
		if (ft_check_input_limits(argv, meta) == 0)
			return (0);
		if (ft_load_stack(argv, meta) == 0)
			return (0);
		return (1);
	}
}

/**
 * @brief Process the input list of numbers.
 *
 * Calls the loader function to load numbers into the stack and sets
 * an error flag if there's any issue.
 *
 * @param argc Argument count from the main function.
 * @param argv Argument values from the main function.
 * @param meta A pointer to the meta_data structure.
 * @return Always returns 1.
 */
int	ft_process_list(int argc, char *argv[], t_meta_data *meta)
{
	if (ft_loader_select(argc, argv, meta) == 0)
		meta->error = 1;
	return (1);
}

/**
 * @brief Process the list of commands to manipulate the stacks.
 *
 * Reads commands from the standard input and processes them in order.
 * Updates the total moves count in the meta data.
 *
 * @param argc Argument count from the main function.
 * @param meta A pointer to the meta_data structure.
 */
void	ft_process_commands(int argc, t_meta_data *meta)
{
	char	*line;
	int		i;

	i = 0;
	while (argc)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strncmp(line, "\n", 1) == 0)
			break ;
		i++;
		ft_get_command(meta, line);
	}
	meta->moves = i;
}
