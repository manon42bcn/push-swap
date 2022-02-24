/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:58:50 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 15:58:52 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_push_swap_two(t_stacks *stack)
{
	if (stack->stack_a[0] < stack->stack_a[1])
		return (write(1, "\n", 1));
	else
		ft_swap(&stack->stack_a[0], &stack->stack_a[1]);
	return (ft_swap(stack, 'a'));
}

int ft_push_swap_tree(t_stacks *stack)
{
	int	centre;

	centre = ft_pick_pivot(stack->stack_a[0], stack->stack_a[1], stack->stack_a[2]);
	if (stack->stack_a[1] == centre)
	{
		if (stack->stack_a[0] > stack->stack_a[2])
		{
			ft_swap(&stack->stack_a[0], &stack->stack_a[2]);
			return (write(1, "ra\n", 3));
		}
			
		else
			return (0);
	}
	else
	{
		if (stack->stack_a[0] == centre)
		{
			ft_swap(&stack->stack_a[0], &stack->stack_a[1]);
			return (write(1, "sa\n", 3) + ft_push_swap_tree(stack));
		}
		else
		{
			ft_swap(&stack->stack_a[0], &stack->stack_a[2]);
			return (write(1, "ra\n", 3) + ft_push_swap_tree(stack));
		}

	}
}
