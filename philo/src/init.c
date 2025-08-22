/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:50:23 by samperez          #+#    #+#             */
/*   Updated: 2025/08/22 14:14:32 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Int variables not allocated, just free the thread / mutex
int	init_struct(t_rules *r, char **argv, int argc)
{
	r->n_philo = (int) ft_atol(argv[1]);
	r->time_to_die = (int) ft_atol(argv[2]);
	r->time_to_eat = (int) ft_atol(argv[3]);
	r->time_to_sleep = (int) ft_atol(argv[4]);
	r->start_time = get_time_ms();
	if (argc == 6)
		r->n_must_eat = (int) ft_atol(argv[5]);
	else
		r->n_must_eat = -1;
	r->philo = malloc(r->n_philo * sizeof(t_philo));
	if (!r->philo)
	{
		free(r);
		return (EXIT_FAILURE);
	}
	r->forks = malloc(r->n_philo * sizeof(pthread_mutex_t));
	if (!r->forks)
	{
		free(r->philo);
		free(r);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	threads(t_rules *r)
{
	pthread_t	master;
	int			i;

	i = 0;
	if (pthread_create(&master, NULL, &watcher, r) != 0)
		return (free_all(r));
	while (i < r->n_philo)
	{
		if (pthread_create(&r->philo[i].thrd, NULL, &rtn, &r->philo[i]) != 0)
			return (free_all(r));
		i++;
	}
	i = 0;
	while (i < r->n_philo)
		if (pthread_join(r->philo[i++].thrd, NULL) != 0)
			return (destroy_mutex(r));
	if (pthread_join(master, NULL) != 0)
		return (destroy_mutex(r));
	return (EXIT_SUCCESS);
}

// Move thread creation to another function and create watcher thread
// Implement error checking for pthread_create and pthread_join
int	init_philos(t_rules *r, int i)
{
	while (i < r->n_philo)
	{
		r->philo[i].r = r;
		if (pthread_mutex_init(&r->forks[i++], NULL) != 0)
			return (free_all(r));
	}
	i = 0;
	while (i < r->n_philo)
	{
		r->philo[i].id = i + 1;
		r->philo[i].times_eaten = 0;
		r->philo[i].is_eating = 0;
		r->philo[i].last_meal = get_time_ms();
		r->philo[i].r_fork = &r->forks[i];
		if (r->philo[i].id == 1)
			r->philo[i].l_fork = &r->forks[r->n_philo - 1];
		else
			r->philo[i].l_fork = &r->forks[i - 1];
		i++;
	}
	return (EXIT_SUCCESS);
}
