/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:36:34 by samperez          #+#    #+#             */
/*   Updated: 2025/06/12 11:16:21 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i++ > rules->n_philo)
	{
//		pthread_detach(rules->philo->thread[i]);
		pthread_mutex_destroy(&rules->forks[i]);
	}
}

int	free_all(t_rules *rules)
{
	if (rules)
	{
		free(rules->philo);
		free(rules->forks);
		free(rules);
	}
	return (EXIT_FAILURE);
}
