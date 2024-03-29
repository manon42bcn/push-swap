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
# include "../libft/inc/libft.h"

/**
 * @struct t_stacks
 * @brief  Node structure representing each element in the stack.
 *
 * Each node in the stack contains an integer value and a pointer to the
 * next node in the stack.
 *
 * @var t_stacks::value
 * The integer value of the node.
 *
 * @var t_stacks::next
 * A pointer to the next node in the stack. If this is the last node in
 * the stack, this pointer will be NULL.
 */
typedef struct s_stacks
{
	int				value;
	struct s_stacks	*next;
}	t_stacks;

/**
 * @struct t_meta_data
 * @brief  Contains meta data and pointers to the main stacks used in the
 * program.
 *
 * This structure acts as the primary container for the program's data,
 * including both the A and B stacks and various meta information about
 * the current state of the sorting algorithm.
 *
 * @var t_meta_data::size
 * Total size or number of elements in stack A.
 *
 * @var t_meta_data::min_val
 * The smallest integer value across both stacks.
 *
 * @var t_meta_data::max_val
 * The largest integer value across both stacks.
 *
 * @var t_meta_data::moves
 * The number of moves or operations performed.
 *
 * @var t_meta_data::sim
 * [Description for this variable]
 *
 * @var t_meta_data::cuts
 * [Description for this variable]
 *
 * @var t_meta_data::first_a
 * A pointer to the first node in stack A.
 *
 * @var t_meta_data::first_b
 * A pointer to the first node in stack B.
 *
 * @var t_meta_data::pivot
 * A pointer to the pivot node, useful in certain sorting techniques.
 */
typedef struct s_meta_data
{
	int					size;
	int					min_val;
	int					max_val;
	int					moves;
	int					sim;
	int					cuts;
	struct s_stacks		*first_a;
	struct s_stacks		*first_b;
	struct s_stacks		*pivot;
}	t_meta_data;

void		ft_swap_action(t_meta_data *meta, char ab);
void		ft_rotate_action(t_meta_data *meta, char ab);
void		ft_reverse_rotate_action(t_meta_data *meta, char ab);
void		ft_push_action(t_meta_data *meta, char ab);
int			ft_prepare_spin(t_meta_data *meta);
int			ft_select_cases(t_meta_data *meta);
int			ft_check_solve(t_meta_data *meta);
int			ft_check_solve_stack(t_meta_data *meta, char ab);
void		ft_delete_node(t_stacks *node);
int			ft_clear_split(char **split);
int			ft_clear_all(t_meta_data *meta);
int			ft_do_push(t_meta_data *meta, char ab);
int			ft_do_rotate(t_meta_data *meta, char ab);
int			ft_do_reverse_rotate(t_meta_data *meta, char ab);
int			ft_do_swap(t_meta_data *meta, char ab);
int			ft_do_while(t_meta_data *meta, int i, char ab,
				int (*act)(t_meta_data *, char));
int			ft_find_best_pivot(t_meta_data *meta);
int			ft_send_to_atoi(char *str);
t_meta_data	*ft_meta_data_init(void);
t_stacks	*ft_create_elem(int value, t_meta_data *meta);
int			ft_load_stack(char **input, int init, t_meta_data *meta);
t_stacks	*ft_get_node_from_index(t_meta_data *meta, char ab, int index);
int			ft_get_index_from_node(t_meta_data *meta, char ab,
				t_stacks *to_find);
t_stacks	*ft_get_node_from_value(t_meta_data *meta, char ab, int value);
int			ft_get_index_from_value(t_meta_data *meta, char ab, int value);
int			ft_get_value_node(t_meta_data *meta, int index, char ab);
int			ft_presort_at_b(t_meta_data *meta);
int			ft_small_cases(t_meta_data *meta, char ab);
int			ft_max_at_stack(t_meta_data *meta, char ab);
int			ft_min_at_stack(t_meta_data *meta, char ab);	
int			ft_find_next(t_meta_data *meta, char ab, int index);
int			ft_find_prev(t_meta_data *meta, char ab, int index);
t_stacks	*ft_last_node(t_meta_data *meta, char ab);
int			ft_find_place(t_meta_data *meta, int value);
int			ft_spin_sort_at_a(t_meta_data *meta);
int			ft_get_sub_stack_limits(t_meta_data *meta);
int			ft_pulling_back_all_stack(t_meta_data *meta);
int			ft_absolute(int n);
int			ft_list_size(t_stacks *first_node);
t_stacks	*ft_select_stack(t_meta_data *meta, char ab);

#endif
