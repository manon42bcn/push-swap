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
	int	first;
	int	last;
	int	size;
} t_stacks;

// Crear pivote medio de tres ... primero, ultimo y centro...
int	ft_pick_pivot(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}

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

int ft_load_stack(int argc, char *argv[], t_stacks *stack)
{
	int	*stack_a;
	int	i;
	int	num;

	i = 1;
	stack->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	stack->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (stack->stack_a == NULL || stack->stack_b == NULL)
		return (0);
	while (i < argc && argv[i])
	{
		num = ft_atoi(argv[i]);
		if (i == 1)
			stack->first = num;
		if (ft_check_stack(&stack->stack_a[0], num) == 1)
		{
			free (stack->stack_a);
			free (stack->stack_b);
			return (0);
		}
		else
			stack->stack_a[i - 1] = num;
		i++;
	}
	stack->size = --i;
	stack->last = stack->stack_a[i - 1];
	return (1);
}

int main(int argc, char *argv[])
{

	int i;
	t_stacks *stack;

	stack = (t_stacks *)malloc(sizeof(t_stacks));
	if (stack == NULL)
		return (0);
	if(ft_load_stack(argc, argv, stack) == 0)
	{
		printf("error");
		return (0);
	}
	
	i = 0;
	while (stack->stack_a[i])
	{
		printf("%i\n", stack->stack_a[i]);
		i++;
	}
	printf("size %i first %i last %i\n", stack->size, stack->first, stack->last);
	printf("checking pivot: %i - centre %i - pivot %i\n", stack->size / 2, stack->stack_a[stack->size / 2], ft_pick_pivot(stack->first, stack->last, stack->stack_a[stack->size / 2]));
	return 0;
}
