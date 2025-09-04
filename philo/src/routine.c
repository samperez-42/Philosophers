/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/09/04 13:10:59 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->r->death_lock);
	if (philo->r->death == 1)
	{
		pthread_mutex_unlock(&philo->r->death_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->r->death_lock);
	return (1);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		philo_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->l_fork);
		philo_msg("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		philo_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->r_fork);
		philo_msg("has taken a fork", philo);
	}
	philo_msg("is eating", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time_ms() - philo->r->start_time;
	philo->meals++;
	ft_usleep(philo->r->time_to_eat);
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	lonely_rtn(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo_msg("has taken a fork", philo);
	philo_msg("has no one to eat with him, how sad", philo);
	ft_usleep(philo->r->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
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
	while (philo_loop(philo) == 1)
	{
		eat(philo);
		pthread_mutex_lock(&philo->meal_lock);
		if (philo->meals == philo->r->n_meals)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_lock);
		philo_msg("is sleeping", philo);
		ft_usleep(philo->r->time_to_sleep);
		philo_msg("is thinking", philo);
	}
	return (philo);
}
