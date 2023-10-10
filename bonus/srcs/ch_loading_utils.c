/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_loading_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:26:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:12:21 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/**
 * @brief Checks if the given number is already in stack A.
 *
 * @param meta A pointer to the meta_data structure.
 * @param num The number to be checked.
 * @return Returns 1 if the number is unique, 0 if it's a duplicate.
 */
static int	ft_check_input(t_meta_data *meta, int num)
{
	t_stacks	*node;

	if (meta->first_a == NULL)
		return (1);
	else
	{
		node = meta->first_a;
		while (node)
		{
			if (num == node->value)
				return (0);
			node = node->next;
		}
		return (1);
	}
}

/**
 * @brief Creates a new node for the stack with the given value.
 *
 * This function first checks if the value is already in stack A
 * to ensure uniqueness and then creates the node if unique.
 *
 * @param meta A pointer to the meta_data structure.
 * @param value The value to be added to the new node.
 * @return Returns a pointer to the new node if successful, NULL otherwise.
 */
static t_stacks	*ft_create_elem(t_meta_data *meta, int value)
{
	t_stacks	*node;

	if (ft_check_input(meta, value) == 0)
		return (NULL);
	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/**
 * @brief Checks if the input values are within the integer limits.
 *
 * This function processes the input strings and ensures that each
 * string represents a valid integer within the boundaries.
 *
 * @param input Array of input strings.
 * @param meta A pointer to the meta_data structure.
 * @return Returns 1 if all input values are valid, 0 otherwise.
 */
int	ft_check_input_limits(char **input, t_meta_data *meta)
{
	int	i;

	if (ft_strncmp(input[meta->init], "--count", 7) == 0)
	{
		meta->count = 1;
		meta->init++;
	}
	i = meta->init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Initializes the meta_data structure.
 *
 * Allocates and initializes the meta_data structure which holds
 * essential information and pointers for the sort algorithm.
 *
 * @return Returns a pointer to the initialized meta_data structure
 * if successful, NULL otherwise.
 */
t_meta_data	*ft_meta_data_init(void)
{
	t_meta_data	*rst;

	rst = (t_meta_data *)malloc(sizeof(t_meta_data));
	if (rst == NULL)
		return (NULL);
	rst->moves = 0;
	rst->error = 0;
	rst->count = 0;
	rst->init = 0;
	rst->first_a = NULL;
	rst->first_b = NULL;
	return (rst);
}

/**
 * @brief Populates stack A from the input values.
 *
 * This function processes the input strings, converts them
 * to integers, and loads them into stack A.
 *
 * @param input Array of input strings.
 * @param meta A pointer to the meta_data structure.
 * @return Returns 1 if the loading was successful, 0 otherwise.
 */
int	ft_load_stack(char **input, t_meta_data *meta)
{
	int			i;
	t_stacks	*stack;
	t_stacks	*new;

	i = meta->init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		new = ft_create_elem(meta, ft_atoi(input[i]));
		if (new == NULL)
			return (0);
		if (meta->first_a == NULL)
		{
			stack = new;
			meta->first_a = new;
		}
		else
		{
			stack->next = new;
			stack = stack->next;
		}
		i++;
	}
	return (1);
}
