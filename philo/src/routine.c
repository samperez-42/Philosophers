/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/08/11 12:49:59 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Gets the total time in milliseconds since the EPOC
uint64_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000ULL) + (tv.tv_usec / 1000ULL));
}

void	philo_msg(char *s, t_philo *philo)
{
	size_t	time;

	time = get_time_ms() - philo->rules->start_time;
	printf("%ldms - %d %s\n", time, philo->id, s);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_msg("says hello\n", philo);
	return (NULL);
}
