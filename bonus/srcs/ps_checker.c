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

void ft_print_stacks(t_meta_data *meta)
{
	t_stacks *node_a;
	t_stacks *node_b;

	node_a = meta->first_a;
	node_b = meta->first_b;
	printf("_MOVES_ %i\n", 1);
	if (node_a || node_b)
		printf ("_STACK_A_ | _STACK_B_\n");
	while (node_a || node_b)
	{
		if (node_a)
			printf("% 9i ", node_a->value);
		if (node_b)
			printf("| % 9i", node_b->value);
		printf("\n");
		if (node_a)
			node_a = node_a->next;
		if (node_b)
			node_b = node_b->next;
		if (!node_a && !node_b)
			break;
	}
}

int ft_check_input_limits(char **input, int init)
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

int ft_loader_select(int argc, char *argv[], t_meta_data *meta)
{
	char	**list;
	
	if (argc == 1)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
			return(0);
		if (ft_check_input_limits(list, 0) == 0)
			return (ft_clear_split(list));
		if (ft_load_stack(list, 0, meta) == 0)
			return (ft_clear_split(list) + ft_clear_all(meta));
		ft_clear_split(list);
		return (1);
	}
	else
	{
		if (ft_check_input_limits(argv, 1) == 0)
			return (0);
		if (ft_load_stack(argv, 1, meta) == 0)
			return (ft_clear_all(meta));
		return (1);
	}
}

void	ft_process_commands(int argc, t_meta_data *meta)
{
	char	*line;

	if (argc == 1)
		return ;
	while (argc)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break;
		ft_get_command(meta, line);
	}
	if (ft_check_solve(meta) == 0)
		ft_putendl_fd("KO", STDOUT_FILENO);
	else
		ft_putendl_fd("OK", STDOUT_FILENO);
}

int	ft_process_list(int argc, char *argv[], t_meta_data *meta)
{
	if (ft_loader_select(argc, argv, meta) == 0)
		return (0);
	return (1);
}

int main(int argc, char *argv[])
{
	t_meta_data	*meta;

	meta = ft_meta_data_init();
	if (meta == NULL)
		return (0);
	if (ft_process_list(argc, argv, meta) == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (ft_clear_all(meta));
	}
	if (ft_check_solve(meta) == 1)
		return (ft_clear_all(meta));
	ft_process_commands(argc, meta);
	ft_clear_all(meta);
	return (0);
}
