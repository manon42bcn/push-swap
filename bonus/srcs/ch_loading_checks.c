/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_loading_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:13:03 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:16:27 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a printable whitespace.
 *
 * @param c Character to check.
 * @return Returns 1 if the character is a whitespace, 0 otherwise.
 */
static int	ft_atoi_isprint(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\t');
}

/**
 * @brief Processes spaces and potential sign characters in the string.
 *
 * Skips over whitespace characters and updates the pointer accordingly.
 * Also handles the presence of a '+' or '-' sign at the beginning of the string.
 *
 * @param str Input string.
 * @param i Pointer to the current index in the string.
 * @param rst Pointer to the current result value.
 */
static void	ft_atoi_spaces(char *str, int *i, long long int *rst)
{
	while (ft_atoi_isprint(str[*(i)]) == 1)
			*(i) = *(i) + 1;
	if (str[*(i)] == '-' || str[*(i)] == '+')
	{
		if (str[*(i)] == '-')
			rst[1] = rst[1] * -1;
		*(i) = *(i) + 1;
	}
}

/**
 * @brief Tests the validity of the resulting integer conversion.
 *
 * Ensures the integer value being constructed doesn't exceed
 * the bounds of an int type. Takes into account potential sign.
 *
 * @param rst Pointer to an array containing the current result and sign.
 * @param c Current character being processed.
 * @return Returns 1 if the conversion is valid, 0 or -1 otherwise.
 */
static int	ft_atoi_test(long long int *rst, char c)
{
	long long int	test;

	test = rst[0] * 10 + (c - '0');
	if (rst[1] == -1)
	{
		if (test > 2147483648)
			return (0);
	}
	else
	{
		if (test > 2147483647)
			return (-1);
	}
	rst[0] = test;
	rst[2] = test * rst[1];
	return (1);
}

/**
 * @brief Converts a string to an integer, ensuring the conversion is valid.
 *
 * Processes the string, ensuring the characters are valid for integer
 * conversion and that the resulting integer doesn't exceed the bounds
 * of the int type.
 *
 * @param str Input string.
 * @return Returns 1 if the conversion was successful, 0 or -1 otherwise.
 */
int	ft_send_to_atoi(char *str)
{	
	long long int	rst[3];
	int				test;
	int				i;

	rst[0] = 0;
	rst[1] = 1;
	rst[2] = 0;
	i = 0;
	ft_atoi_spaces(str, &i, &rst[0]);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		else if (str[i] >= '0' && str[i] <= '9')
		{	
			test = ft_atoi_test(&rst[0], str[i]);
			if (test != 1)
				return (test);
		}
		i++;
	}
	return (1);
}
