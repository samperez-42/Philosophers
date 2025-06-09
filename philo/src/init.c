/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:07:15 by samperez          #+#    #+#             */
/*   Updated: 2025/06/09 14:11:51 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Int variables not allocated, just free the thread / mutex
int	init_rules(t_rules *rules, t_philo *philo, char **argv, int argc)
{
	rules->n_philo = (int) ft_atol(argv[1]);
	rules->time_to_die = (int) ft_atol(argv[2]);
	rules->time_to_eat = (int) ft_atol(argv[3]);
	rules->time_to_sleep = (int) ft_atol(argv[4]);
	if (argc == 6)
		rules->n_must_eat = (int) ft_atol(argv[5]);
	rules->philo = philo;
	rules->forks = malloc(rules->n_philo * sizeof(pthread_mutex_t));
	if (!rules->forks)
	{
		free(rules->philo);
		free(rules);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_philos(t_rules *rules, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		philosophers[i].id = i + 1;
//		pthread_mutex_init(&rules->forks[i], NULL);
//		philosophers[i].right_fork = &rules->forks[i];
		if (philosophers[i].id % 2 == 0)
		{
//			philosophers[i].left_fork = &rules->forks[i - 1];
			printf("Mi id es %d y soy par\n", philosophers[i].id);
		}
//		pthread_create(philosophers[i].thread, NULL, &routine, );
		i++;
	}
	return (EXIT_SUCCESS);
}
