/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:50:23 by samperez          #+#    #+#             */
/*   Updated: 2025/08/19 21:42:05 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Int variables not allocated, just free the thread / mutex
int	init_struct(t_rules *rules, char **argv, int argc)
{
	rules->n_philo = (int) ft_atol(argv[1]);
	rules->time_to_die = (int) ft_atol(argv[2]);
	rules->time_to_eat = (int) ft_atol(argv[3]);
	rules->time_to_sleep = (int) ft_atol(argv[4]);
	rules->start_time = get_time_ms();
	if (argc == 6)
		rules->n_must_eat = (int) ft_atol(argv[5]);
	else
		rules->n_must_eat = -1;
	rules->philo = malloc(rules->n_philo * sizeof(t_philo));
	if (!rules->philo)
	{
		free(rules);
		return (EXIT_FAILURE);
	}
	rules->forks = malloc(rules->n_philo * sizeof(pthread_mutex_t));
	if (!rules->forks)
	{
		free(rules->philo);
		free(rules);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Move thread creation to another function and create watcher thread
// Implement error checking for pthread_create and pthread_join
int	init_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
		rules->philo[i++].rules = rules;
	i = 0;
	while (i < rules->n_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].times_eaten = 0;
		rules->philo[i].is_eating = 0;
		rules->philo[i].last_meal = get_time_ms();
		pthread_mutex_init(&rules->forks[i], NULL);
		rules->philo[i].right_fork = &rules->forks[i];
		if (rules->philo[i].id == 1)
			rules->philo[i].left_fork = &rules->forks[rules->n_philo];
		else
			rules->philo[i].left_fork = &rules->forks[i - 1];
		pthread_create(&rules->philo[i].thrd, NULL, &routine, &rules->philo[i]);
		pthread_join(rules->philo[i].thrd, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
