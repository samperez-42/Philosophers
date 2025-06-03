/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:31:19 by samperez          #+#    #+#             */
/*   Updated: 2025/06/03 11:16:14 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_before(const char *nptr, int *i, int *neg)
{
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	if (nptr[*i] == '+')
	{
		(*i)++;
	}
	else if (nptr[*i] == '-')
	{
		(*i)++;
		(*neg)++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 0;
	res = 0;
	if (nptr[i] == 0)
		return (0);
	check_before(nptr, &i, &neg);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

// Compares 'n' characters of two strings
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_non_numeric(char **argv)
{
	int		i;
	int		tmp;
	char	*tmp2;

	i = 1;
	tmp = 0;
	tmp2 = NULL;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp < 0)
			return (EXIT_FAILURE);
		tmp2 = ft_itoa(tmp);
		if (ft_strncmp(argv[i], tmp2, ft_strlen(argv[i])))
			return (EXIT_FAILURE);
		free(tmp2);
		i++;
	}
	return (EXIT_SUCCESS);
}
