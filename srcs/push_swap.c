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

/**
 * @brief Checks if the input values are within valid limits.
 *
 * Iterates through the input strings and checks if they are valid integers.
 * 
 * @param input Array of strings to check.
 * @param init Starting index in the input array.
 * 
 * @return Returns 1 if all strings are valid integers, 0 otherwise.
 */
int	ft_check_input_limits(char **input, int init)
{
	int	i;

	i = init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Determines the method to load the data into the stack.
 *
 * If the argument count equals 2, it splits the input string and loads it
 * into the stack. If the argument count is greater, it checks each argument
 * for input limits and loads them directly into the stack.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param meta Metadata structure.
 * 
 * @return Returns 1 if loading was successful, 0 otherwise.
 */
int	ft_loader_select(int argc, char *argv[], t_meta_data *meta)
{
	char	**list;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
			return (0);
		if (ft_check_input_limits(list, 0) == 0)
			return (ft_clear_split(list));
		if (ft_load_stack(list, 0, meta) == 0)
			return (ft_clear_split(list));
		ft_clear_split(list);
		return (1);
	}
	else
	{
		if (ft_check_input_limits(argv, 1) == 0)
			return (0);
		if (ft_load_stack(argv, 1, meta) == 0)
			return (0);
		return (1);
	}
}

/**
 * @brief Processes the input list for the swap operation.
 *
 * Checks the input values and performs the necessary operations to prepare
 * and optimize the list for the swap operation.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param meta Metadata structure.
 * 
 * @return Returns 1 if the process was successful, 0 otherwise.
 */
int	ft_process_list(int argc, char *argv[], t_meta_data *meta)
{
	if (ft_loader_select(argc, argv, meta) == 0)
		return (0);
	if (meta->size == 1)
		return (1);
	if (ft_check_solve(meta) == 1)
		return (1);
	ft_find_best_pivot(meta);
	if (ft_get_sub_stack_limits(meta) == 0)
		return (0);
	if (ft_select_cases(meta) == 0)
		return (0);
	return (1);
}

/**
 * @brief Main function of the pusw_swap project.
 *
 * Initializes metadata and processes the input list. Outputs an error to 
 * STDERR if processing fails.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * 
 * @return Returns 0 in all cases.
 */
int	main(int argc, char *argv[])
{
	t_meta_data	*meta;

	meta = ft_meta_data_init();
	if (meta == NULL)
		return (0);
	if (argc == 1)
		return (ft_clear_all(meta));
	if (ft_process_list(argc, argv, meta) == 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	ft_clear_all(meta);
	return (0);
}
