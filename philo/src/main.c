/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:04 by samperez          #+#    #+#             */
/*   Updated: 2025/06/06 11:34:10 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Int variables not allocated, just free the thread / mutex
int	init_struct(t_philo *philo, char **argv, int argc)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->n_must_eat = ft_atoi(argv[5]);
	philo->philosophers = malloc(philo->n_philo * sizeof(pthread_t));
	if (!philo->philosophers)
	{
		free(philo);
		return (EXIT_FAILURE);
	}
	philo->forks = malloc(philo->n_philo * sizeof(pthread_mutex_t));
	if (!philo->forks)
	{
		free(philo->philosophers);
		free(philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_params(argc, argv))
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (printf("Error: Malloc failed\n"), EXIT_FAILURE);
	if (init_struct(philo, argv, argc))
		return (printf("Failed to init the struct\n"), EXIT_FAILURE);
	free_all(philo);
	return (EXIT_SUCCESS);
}
