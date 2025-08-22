/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:49:46 by samperez          #+#    #+#             */
/*   Updated: 2025/08/20 10:37:14 by samperez         ###   ########.fr       */
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

void	philo_msg(char *s, t_philo *philo)
{
	size_t	time;

	time = get_time_ms() - philo->r->start_time;
	printf("%ldms - Philo %d %s\n", time, philo->id, s);
}
