/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:47:04 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 17:47:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int main(int argc, char const *argv[])
{
	char *line;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break;
		printf("%s", line);
	}
	return 0;
}
