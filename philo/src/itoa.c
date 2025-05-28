/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:31:50 by samperez          #+#    #+#             */
/*   Updated: 2025/05/28 16:32:22 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Counts how many bytes needed for malloc
static int	count_digits(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static void	*int_to_string(char *s, long int n, int is_negative)
{
	char	tmp;
	int		i;

	i = count_digits(n) - 1;
	if (is_negative == 1)
	{
		s[0] = '-';
		i++;
		s[count_digits(n) + 1] = '\0';
	}
	else
		s[count_digits(n)] = '\0';
	tmp = 0;
	while (n > 0)
	{
		tmp = (n % 10) + '0';
		n /= 10;
		s[i] = tmp;
		i--;
	}
	return (s);
}

// Special 0 case
static void	*handle_zero(char **s)
{
	*s = malloc(2);
	if (!*s)
		return (NULL);
	(*s)[0] = '0';
	(*s)[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char		*s;
	long int	num;
	int			is_negative;

	num = (long int) n;
	is_negative = 0;
	if (num < 0)
	{
		is_negative++;
		num *= -1;
	}
	if (num == 0)
	{
		handle_zero(&s);
		return (s);
	}
	if (is_negative)
		s = malloc(sizeof(char) * count_digits(num) + 2);
	else
		s = malloc(sizeof(char) * count_digits(num) + 1);
	if (!s)
		return (NULL);
	s = int_to_string(s, num, is_negative);
	return (s);
}
