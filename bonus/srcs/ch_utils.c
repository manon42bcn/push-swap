/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:28:39 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Checks if the list is sorted in ascending order.
 *
 * This function inspects the stack 'a' to see if the elements are in
 * ascending order and that stack 'b' is empty.
 *
 * @param meta Pointer to metadata containing information about the stacks.
 * @return Returns 1 if the list is sorted, 0 otherwise.
 */
int	ft_check_solve(t_meta_data *meta)
{
	int			i;
	int			prev;
	t_stacks	*stack;

	i = 0;
	if (meta->first_b != NULL)
		return (0);
	stack = meta->first_a;
	prev = stack->value;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Gets the size of the linked list.
 *
 * This function iterates through the linked list starting from the first_node
 * and returns its size.
 *
 * @param first_node Pointer to the first node of the linked list.
 * @return Returns the number of nodes in the linked list.
 */
int	ft_list_size(t_stacks *first_node)
{
	t_stacks	*node;
	int			i;

	node = first_node;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

/**
 * @brief Checks if there are any errors in the solution.
 *
 * This function reads a line from standard input to check for the solution.
 *
 * @return Returns 1 if no errors are found, otherwise returns 0.
 */
int	ft_check_error_solve(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (1);
	return (0);
}

/**
 * @brief Prints results based on the provided message code.
 *
 * Based on the provided message code, this function prints the result
 * to the appropriate output stream (stdout or stderr).
 *
 * @param msg Message code (0: KO, 1: OK, 2: Error).
 * @param meta Pointer to metadata (used for the moves count).
 */
void	ft_print_results(int msg, t_meta_data *meta)
{
	if (msg == 0)
		ft_putendl_fd("KO", STDOUT_FILENO);
	if (msg == 1)
	{
		if (meta->count == 1)
		{
			ft_putnbr_fd(meta->moves, STDOUT_FILENO);
			ft_putstr_fd(" moves ", STDOUT_FILENO);
		}
		ft_putendl_fd("OK", STDOUT_FILENO);
	}
	if (msg == 2)
		ft_putendl_fd("Error", STDERR_FILENO);
}
