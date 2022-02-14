/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_load_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:14:41 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/14 18:14:44 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/ft_atoi.c"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	pivot;
} t_stacks;

// Crear pivote medio de tres ... primero, ultimo y centro...

int ft_check_stack(int *stack, int num)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int *ft_load_stack(int argc, char *argv[])
{
	int	*stack_a;
	int	i;
	int	num;

	i = 1;
	stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	if (stack_a == NULL)
		return (NULL);
	while (i < argc && argv[i])
	{
		num = ft_atoi(argv[i]);
		if (ft_check_stack(&stack_a[0], num) == 1)
		{
			free (stack_a);
			return (0);
		}
		else
			stack_a[i - 1] = num;
		i++;
	}
	return (stack_a);
}

int main(int argc, char *argv[])
{

	int i;
	int *stack_a;

	stack_a = ft_load_stack(argc, argv);
	if (stack_a == 0)
		printf("error");
	else
	{
		i = 0;
		while (stack_a[i])
		{
			printf("%i\n", stack_a[i]);
			i++;
		}
	}
	return 0;
}
