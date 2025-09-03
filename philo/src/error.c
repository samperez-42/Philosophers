/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:36:34 by samperez          #+#    #+#             */
/*   Updated: 2025/09/03 14:41:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	destroy_mutex(t_rules *r)
{
	int	i;

	i = 0;
	while (i < r->n_philo)
	{
		pthread_mutex_destroy(&r->forks[i]);
		pthread_mutex_destroy(&r->philo[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&r->death_lock);
	pthread_mutex_destroy(&r->write_lock);
	return (EXIT_FAILURE);
}

int	free_all(t_rules *r)
{
	if (r)
	{
		if (r->forks)
		{
			destroy_mutex(r);
			free(r->forks);
		}
		if (r->philo)
			free(r->philo);
		free(r);
	}
	return (EXIT_FAILURE);
}
