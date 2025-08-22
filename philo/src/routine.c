/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/08/22 14:06:35 by samperez         ###   ########.fr       */
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

// To do:
// Take fork / Eat / Pass fork  / Sleep / Think / Repeat
/* void	philos_routine(t_philo *philo)
{
	
} */

void	*rtn(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->r->n_philo == 1)
	{
		philo_msg("has taken a fork", philo);
		ft_usleep(philo->r->time_to_die);
		philo_msg("has no one to eat with him, how sad, he died", philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		ft_usleep(2);
	/* while (not_dead() == EXIT_SUCCESS)
		philos_routine(philo); */
	philo_msg("says hello\n", philo);
	return (philo);
}
