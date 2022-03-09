/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:59:38 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 20:00:41 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
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
	int					sim;
	int					cuts;
	struct s_stacks		*first_a;
	struct s_stacks		*first_b;
	struct s_stacks		*sub_stack;
	struct s_stacks		*pivot;
}	t_meta_data;

char	*get_next_line(int fd);
char	*ft_substr_gnl(char *s, int start, int len, int *nl_len);
char	*ft_strjoin_gnl(char *s1, char *s2, int bytes, int *nl_len);


#endif
