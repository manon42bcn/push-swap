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
# include "../libft/libft.h"

typedef struct s_stacks
{
	int				value;
	struct s_stacks	*next;
}	t_stacks;

typedef struct s_meta_data
{
	int					size;
	int					min_val;
	int					max_val;
	int					moves;
	struct s_stacks		*first_a;
	struct s_stacks		*first_b;
	struct s_meta_data	*pivots_stacks;
	struct s_meta_data	*forced_pivots;
	struct s_stacks		*pivot;
}	t_meta_data;

void		ft_swap_action(t_meta_data *meta, char ab);
void		ft_rotate_action(t_meta_data *meta, char ab);
void		ft_reverse_rotate_action(t_meta_data *meta, char ab);
void		ft_push_action(t_meta_data *meta, char ab);
int			ft_pulling_back_all_stack(t_meta_data *meta);
int			ft_push_all_stack(t_meta_data *meta);
int			ft_solve_two_numbers(t_meta_data *meta, char ab);
int			ft_solve_two_paralles(t_meta_data *meta);
int			ft_select_cases(t_meta_data *meta);
int			ft_do_push(t_meta_data *meta, char ab);
int			ft_do_rotate(t_meta_data *meta, char ab);
int			ft_do_reverse_rotate(t_meta_data *meta, char ab);
int			ft_do_swap(t_meta_data *meta, char ab);
int			ft_do_sml_push(t_meta_data *meta, char ab);
int			ft_do_sml_rotate(t_meta_data *meta, char ab);
int			ft_do_sml_reverse_rotate(t_meta_data *meta, char ab);
int			ft_do_sml_swap(t_meta_data *meta, char ab);
t_meta_data	*ft_meta_data_init(void);
int			ft_check_stack(t_meta_data *meta, int num);
t_stacks	*ft_create_elem(int value, t_meta_data *meta);
t_stacks	*ft_load_stack(int argc, char *argv[], t_meta_data *meta);
int			ft_small_cases(t_meta_data *meta, char ab);
int			ft_max_at_stack(t_meta_data *meta, char ab);
int			ft_min_at_stack(t_meta_data *meta, char ab);	
int			ft_find_next(t_meta_data *meta, char ab, int index);
int			ft_middle_point(t_meta_data *meta, char ab);
int			ft_find_prev(t_meta_data *meta, char ab, int index);
int			ft_list_size(t_stacks *first_node);
t_stacks	*ft_select_stack(t_meta_data *meta, char ab);
t_stacks	*ft_last_node(t_meta_data *meta, char ab);
int			ft_get_value_node(t_meta_data *meta, int index, char ab);
int			ft_value_position(t_meta_data *meta, int value, char ab);
int			ft_check_solve(t_meta_data *meta);
int			ft_check_solve_stack(t_meta_data *meta, char ab);
t_stacks	*ft_get_node_from_index(t_meta_data *meta, char ab, int index);
int			ft_get_index_from_node(t_meta_data *meta, char ab, t_stacks *to_find);
int			ft_spin_sort_at_a(t_meta_data *meta);
int			ft_presort_at_b(t_meta_data *meta);
void		ft_clear_all(t_meta_data *meta);
int			*ft_next_distance(t_meta_data *meta, int *lower_upper_size);
int			ft_smaller_than_pivot(t_meta_data *meta, char ab, char se, t_stacks *pivot);
t_stacks	*ft_select_pivot(t_meta_data *meta);
t_stacks	*ft_create_elem_pivot(int value, t_meta_data *meta_pivot);
t_meta_data	*ft_copy_stacks(t_meta_data *meta);
void		ft_delete_node(t_stacks *node);
t_stacks	*ft_get_node_from_value(t_meta_data *meta, char ab, int value);
int			ft_solver_simulator(t_meta_data *meta);
int			ft_sml_next_to_send(t_meta_data *meta);
int			ft_sml_place_at_presort(t_meta_data *meta);
int			ft_sml_presort_at_b(t_meta_data *meta);
int			ft_sml_spin_sort_at_a(t_meta_data *meta);


#endif
