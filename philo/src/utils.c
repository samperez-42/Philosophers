/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:49:46 by samperez          #+#    #+#             */
/*   Updated: 2025/09/15 13:13:03 by samperez         ###   ########.fr       */
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

void	ft_usleep(size_t milliseconds)
{
	uint64_t	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < milliseconds)
		usleep(100);
}

void	lonely_rtn(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_msg("has taken a fork", philo);
	philo_msg("has no one to eat with him, how sad", philo);
	ft_usleep(philo->r->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
	return ;
}

void	philo_msg(char *s, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->r->write_lock);
	time = get_time_ms() - philo->r->start_time;
	if (philo_loop(philo))
		printf("%ld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->r->write_lock);
}
