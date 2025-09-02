/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/09/02 12:23:50 by samperez         ###   ########.fr       */
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

void	eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork);
		philo_msg("has taken the right fork", philo);
		pthread_mutex_lock(philo->l_fork);
		philo_msg("has taken the left fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		philo_msg("has taken the left fork", philo);
		pthread_mutex_lock(philo->r_fork);
		philo_msg("has taken the right fork", philo);
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo_msg("is eating", philo);
	philo->is_eating = 1;
	ft_usleep(philo->r->time_to_eat);
	philo->is_eating = 0;
	philo->last_meal = get_time_ms() - philo->r->start_time;
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

// Take fork / Eat / Pass fork  / Sleep / Think / Repeat
void	philos_routine(t_philo *philo)
{
	eat(philo);
	philo_msg("is sleeping", philo);
	ft_usleep(philo->r->time_to_sleep);
	philo_msg("is thinking", philo);
}

static void	lonely_rtn(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_msg("has taken a fork", philo);
	philo_msg("has no one to eat with him, how sad", philo);
	ft_usleep(philo->r->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
	philo_msg("has died", philo);
	return ;
}

void	*rtn(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->r->n_philo == 1)
	{
		lonely_rtn(philo);
		return (philo);
	}
	while (/* not_dead() == EXIT_SUCCESS ||  */philo->meals != philo->r->n_meals)
		philos_routine(philo);
//	philo_msg("says hello\n", philo);
	return (philo);
}
