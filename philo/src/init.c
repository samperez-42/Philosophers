/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:50:23 by samperez          #+#    #+#             */
/*   Updated: 2025/06/12 11:16:35 by samperez         ###   ########.fr       */
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
	if (argc == 6)
		rules->n_must_eat = (int) ft_atol(argv[5]);
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

int	init_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		rules->philo[i].rules = rules;
		i++;
	}
	i = 0;
	while (i < rules->n_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].times_eaten = 0;
		pthread_mutex_init(&rules->forks[i], NULL);
		rules->philo[i].right_fork = &rules->forks[i];
		pthread_create(&rules->philo[i].thrd, NULL, &routine, &rules->philo[i]);
		pthread_join(rules->philo[i].thrd, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
