/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:17:27 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 16:17:31 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	pivot;
	int	first;
	int	last;
	int	size;
} t_stacks;

#endif
