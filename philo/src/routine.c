/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:27:27 by samperez          #+#    #+#             */
/*   Updated: 2025/08/19 21:28:07 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// To do:
// Take fork / Eat / Pass fork  / Sleep / Think / Repeat
/* void	philos_routine(t_philo *philo)
{
	
} */

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->n_philo == 1)
	{
		philo_msg("has taken a fork", philo);
		ft_usleep(philo->rules->time_to_die);
		philo_msg("has no one to eat with him, how sad, he died", philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep(1);
	/* while (not_dead() == EXIT_SUCCESS)
		philos_routine(philo); */
	philo_msg("says hello\n", philo);
	return (philo);
}
