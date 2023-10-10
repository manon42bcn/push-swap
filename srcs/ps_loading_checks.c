/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_loading_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:13:03 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 22:13:06 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the character is a printable whitespace.
 *
 * The function checks if the character passed is one of the common white spaces 
 * such as space, form-feed, new-line, carriage return, vertical tab, and tab.
 * 
 * @param c Character to be checked.
 * 
 * @return Returns 1 if the character is a printable whitespace, 0 otherwise.
 */
static int	ft_atoi_isprint(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\t');
}

/**
 * @brief Parses the spaces and potential signs in the input string.
 *
 * Skips the whitespace characters at the start of the string and checks 
 * for the presence of '+' or '-' signs. Adjusts the parsing position 
 * and the result value accordingly.
 * 
 * @param str Input string.
 * @param i Pointer to the current parsing position.
 * @param rst Pointer to the result value.
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
 * @brief Checks the result of the atoi conversion for overflow.
 *
 * Tests if the result value, after a new digit is added, overflows 
 * the integer range. Adjusts the result value accordingly.
 * 
 * @param rst Array containing result values and signs.
 * @param c Current character (digit) being parsed.
 * 
 * @return Returns 1 if successful, 0 or -1 for overflow cases.
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
 * @brief Converts the input string to integer and checks for validity.
 *
 * Parses the string, checks for valid characters, and attempts to convert 
 * it to an integer. Validates against integer overflow and non-digit characters.
 * 
 * @param str Input string.
 * 
 * @return Returns 1 if the string is a valid integer, 0 or -1 otherwise.
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
