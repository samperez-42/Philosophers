/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:36:34 by samperez          #+#    #+#             */
/*   Updated: 2025/06/03 12:21:33 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Int variables not allocated, just free the thread / mutex
void	free_all(t_philo *philo)
{
/* 	int	i;

	i = philo->n_philo;
	while (i-- > 0)
	{
		pthread_detach(philo->philosophers[i]);
		pthread_mutex_destroy(&philo->forks[i]);
	} */
	free(philo->philosophers);
	free(philo->forks);
	free(philo);
}
