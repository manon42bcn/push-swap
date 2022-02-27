/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cases_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:25:14 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 22:25:18 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_case_two(t_meta_data *meta)
{
	if (meta->first_a->value > meta->first_a->next->value)
		return (ft_do_swap(meta, 'a'));
	else
		return (0);
}

int ft_case_three(t_meta_data *meta)
{
	int			max;

	if (ft_check_solve(meta) == 1)
		return (0);
	max = ft_max_at_stack(meta, 'a');
	if (max == 1)
		return (ft_do_rotate(meta, 'a') + ft_case_two(meta));
	else if (max == 2)
		return (ft_do_reverse_rotate(meta, 'a') + ft_case_two(meta));
	else
		return (ft_case_two(meta));
}

int ft_case_four(t_meta_data *meta)
{
	int			min;
	int			rst;
	int			max;

	if (ft_check_solve(meta) == 1)
		return (0);
	rst = 0;
	min = ft_min_at_stack(meta, 'a');
	max = ft_max_at_stack(meta, 'a');
	if (min == 1 || max == 1)
	{
		rst += ft_do_push(meta, 'a');
		rst += ft_case_three(meta);
		rst += ft_do_push(meta, 'b');
		if (max == 1)
			rst += ft_do_rotate(meta, 'a');
		return (rst);
	}
	else if (min == 4 || max == 4)
		return (ft_do_rotate(meta, 'a') + ft_case_four(meta));
	else
		return (ft_do_swap(meta, 'a') + ft_case_four(meta));
}

int ft_case_five(t_meta_data *meta)
{
	int			min;
	int			i;

	i = 0;
	if (ft_check_solve(meta) == 1)
		return (0);
	if (ft_list_size(meta->first_a) == 3)
		return (ft_case_four(meta)
			+ ft_pulling_back_all_stack(meta));
	min = ft_min_at_stack(meta, 'a');
	if (min == 0)
		return (ft_pulling_back_all_stack(meta));
	if (min == 1)
		return (ft_do_push(meta, 'a') + ft_case_five(meta));
	if (min <= 3)
		return (ft_do_rotate(meta, 'a') + ft_case_five(meta));
	else
		return (ft_do_reverse_rotate(meta, 'a') + ft_case_five(meta));
}

int ft_select_cases(t_meta_data *meta)
{
	if (meta->size == 1)
		return (0);
	else if (meta->size == 2)
		return (ft_case_two(meta));
	else if (meta->size == 3)
		return (ft_case_three(meta));
	else if (meta->size == 4)
		return (ft_case_four(meta));
	else if (meta->size == 5)
		return (ft_case_five(meta));
}
