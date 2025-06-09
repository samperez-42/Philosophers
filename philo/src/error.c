/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:36:34 by samperez          #+#    #+#             */
/*   Updated: 2025/06/09 14:12:02 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* void	free_philo_fork(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		if (philo[i].thread)
			pthread_detach(philo[i].thread);
		pthread_mutex_unlock(&rules->forks[i]);
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
} */

// Int variables not allocated, just free the thread / mutex
void	free_all(t_rules *rules, t_philo *philo)
{
//	free_philo_fork(rules, philo);
	free(rules->forks);
	free(philo);
	free(rules);
}
