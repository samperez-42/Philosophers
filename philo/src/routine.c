/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/08/22 14:35:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*watcher(void *rule)
{
	t_rules	*r;

	r = (t_rules *)rule;
	printf("%ldms - Master says hello\n\n", (get_time_ms() - r->start_time));
	return (r);
}

// Take fork / Eat / Pass fork  / Sleep / Think / Repeat
void	philos_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_msg("has taked a fork", philo);
	if (philo->r->n_philo == 1)
	{
		ft_usleep(philo->r->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		philo_msg("has no one to eat with him, how sad", philo);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	philo_msg("has taken a fork", philo);
	philo_msg("is eating", philo);
	ft_usleep(philo->r->time_to_eat);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	philo_msg("is sleeping", philo);
	ft_usleep(philo->r->time_to_sleep);
	philo_msg("is thinking", philo);
}

void	*rtn(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(2);
	/* while (not_dead() == EXIT_SUCCESS)
		philos_routine(philo); */
	philo_msg("says hello\n", philo);
	return (philo);
}
