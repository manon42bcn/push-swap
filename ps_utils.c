/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int ft_swap(stack *stack, char ab)
{	
	if (ab = 'a' && stack->size_a >= 2)
	{
		ft_swap(stack->stack_a[stack->sa_from], stack->stack_a[stack->sa_from + 1]);
		write(1, "sa\n", 3);
	}
	else if (ab = 'b' && stack->size_b >= 2)
	{
		ft_swap(stack->stack_b[stack->sb_from], stack->stack_b[stack->sb_from + 1]);
		write(1, "sb\n", 3);
	}
}

int	ft_pick_pivot(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}
