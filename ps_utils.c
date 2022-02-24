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

int ft_swap_stack(t_stacks *stack, char ab)
{	
	if ((ab == 'a' || ab == 's') && stack->size_a >= 2)
		ft_swap(&stack->stack_a[stack->sa_from], &stack->stack_a[stack->sa_from + 1]);
	if ((ab == 'a' || ab == 's') && stack->size_b >= 2)
		ft_swap(&stack->stack_b[stack->sb_from], &stack->stack_b[stack->sb_from + 1]);
	if (ab == 'a' && stack->size_a >= 2)
		return (write(1, "sa\n", 3));
	if (ab == 'b' && stack->size_b >= 2)
		return (write(1, "sb\n", 3));
	if (ab == 's' && stack->size_a >= 2 && stack->size_b >= 2)
		return (write(1, "ss\n", 3));
	return (0);
}

int ft_push_stack(t_stacks *stack, char ab)
{
	if (ab == 'a' && stack->size_b >= 1)
	{
		ft_swap(&stack->stack_b[stack->sb_from], &stack->stack_a[stack->sa_from - 1]);
		stack->size_a++;
		stack->sa_from--;
		stack->size_b--;
		stack->sb_from++;
		return (write(1, "pa\n", 3));
	}
	else if (ab == 'b' && stack->size_a >= 1)
	{
		ft_swap(&stack->stack_a[stack->sa_from], &stack->stack_b[stack->sb_from - 1]);
		stack->size_a--;
		stack->sa_from++;
		stack->size_b++;
		stack->sb_from--;
		return (write(1, "pb\n", 3));
	}
	return (0);
}

int ft_rotate_stack(t_stacks *stack, char ab)
{
	int first;
	int i;

	if (ab == 'a')
	{
		first = stack->stack_a[stack->sa_from];
		i = stack->sa_from - 1;
		while (i++ < stack->size_a)
			ft_swap(&stack->stack_a[i - 1], &stack->stack_a[i]);
		stack->stack_a[stack->size_a - 1] = first;
		return (write(1, "ra\n", 3));
	}
	if (ab == 'b')
	{
		first = stack->stack_b[stack->sb_from];
		i = stack->sb_from - 1;
		while (i++ < stack->size_b)
			ft_swap(&stack->stack_b[i - 1], &stack->stack_b[i]);
		stack->stack_b[stack->size_a - 1] = first;
		return (write(1, "rb\n", 3));
	}
}

int ft_reverse_rotate_stack(t_stacks *stack, char ab)
{
	int first;
	int i;

	if (ab == 'a')
	{
		first = stack->stack_a[stack->size_a - 1];
		i = stack->size_a;
		while (i-- > stack->sa_from)
			ft_swap(&stack->stack_a[i - 1], &stack->stack_a[i]);
		stack->stack_a[stack->sa_from] = first;
		return (write(1, "ra\n", 3));
	}
	if (ab == 'b')
	{
		first = stack->stack_b[stack->sb_from];
		i = stack->size_b;
		while (i-- > stack->sb_from)
			ft_swap(&stack->stack_b[i - 1], &stack->stack_b[i]);
		stack->stack_b[stack->sb_from] = first;
		return (write(1, "rb\n", 3));
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
