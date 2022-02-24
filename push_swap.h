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
 /*
typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int sa_from;
	int sb_from;
	int	pivot;
	int	first;
	int	last;
	int	size;
	int size_a;
	int size_b;
} t_stacks;
*/
typedef struct s_stacks
{
	int				value;
	struct s_stacks	*next;
}	t_stacks

typedef struct s_meta_data
{
	int				size;
	int 			min_val;
	int 			max_val;
	struct t_stacks	*first_a;
	struct t_stacks	*first_b;
}	t_meta_data
#endif
