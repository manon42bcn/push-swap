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
	int				size;
	int 			min_val;
	int 			max_val;
	struct s_stacks	*first_a;
	struct s_stacks	*first_b;
}	t_meta_data;

void		ft_swap_action(t_meta_data *meta, char ab);
void		ft_rotate_action(t_meta_data *meta, char ab);
void		ft_reverse_rotate_action(t_meta_data *meta, char ab);
void		ft_push_action(t_meta_data *meta, char ab);
int 		ft_pulling_back_all_stack(t_meta_data *meta);
int 		ft_push_all_stack(t_meta_data *meta);
int			ft_solve_two_numbers(t_meta_data *meta, char ab);
int 		ft_solve_two_paralles(t_meta_data *meta);
int 		ft_select_cases(t_meta_data *meta);
int			ft_do_push(t_meta_data *meta, char ab);
int 		ft_do_rotate(t_meta_data *meta, char ab);
int			ft_do_reverse_rotate(t_meta_data *meta, char ab);
int			ft_do_swap(t_meta_data *meta, char ab);
t_meta_data	*ft_meta_data_init(void);
int			ft_check_stack(t_meta_data *meta, int num);
t_stacks	*ft_create_elem(int value, t_meta_data *meta);
t_stacks	*ft_load_stack(int argc, char *argv[], t_meta_data *meta);
int			ft_small_cases(t_meta_data *meta);
int 		ft_check_solve(t_meta_data *meta);
int 		ft_max_at_stack(t_meta_data *meta, char ab);
int 		ft_min_at_stack(t_meta_data *meta, char ab);
int 		ft_next_max(t_meta_data *meta, int max, char ab);
int 		ft_next_min(t_meta_data *meta, int min, char ab);
int			ft_list_size(t_stacks *first_node);
t_stacks	*ft_select_stack(t_meta_data *meta, char ab);
t_stacks	*ft_last_node(t_meta_data *meta, char ab);
int			ft_get_value_node(t_meta_data *meta, int index, char ab);
int 		ft_value_position(t_meta_data *meta, int value, char ab);
int 		ft_absolute(int num);
int			ft_pick_pivot(int a, int b, int c);

#endif
