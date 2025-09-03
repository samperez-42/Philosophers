/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:03:53 by samperez          #+#    #+#             */
/*   Updated: 2025/09/03 18:34:24 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_rules *r)
{
	int			flag;
	int			i;
	size_t		t_since_meal;

	flag = 0;
	i = 0;
	t_since_meal = 0;
	while (i < r->n_philo)
	{
		pthread_mutex_lock(&r->philo[i].meal_lock);
		t_since_meal = (get_time_ms() - r->start_time) - r->philo[i].last_meal;
		pthread_mutex_unlock(&r->philo[i].meal_lock);
		if (t_since_meal >= r->time_to_die)
			flag = 1;
		if (flag == 1)
		{
			philo_msg("died", &r->philo[i]);
			pthread_mutex_lock(&r->death_lock);
			r->death = 1;
			pthread_mutex_unlock(&r->death_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_meals(t_rules *r)
{
	int	satisfied_philos;
	int	i;

	satisfied_philos = 0;
	i = 0;
	if (r->n_meals == -1)
		return (0);
	while (i < r->n_philo)
	{
		pthread_mutex_lock(&r->philo[i].meal_lock);
		if (r->philo[i].meals == r->n_meals)
			satisfied_philos++;
		pthread_mutex_unlock(&r->philo[i].meal_lock);
		i++;
	}
	if (satisfied_philos == r->n_philo)
	{
		pthread_mutex_lock(&r->death_lock);
		r->death = 1;
		pthread_mutex_lock(&r->death_lock);
		return (1);
	}
	return (0);
}

void	*watcher(void *rule)
{
	t_rules	*r;

	r = (t_rules *)rule;
	while (1)
	{
		if (check_dead(r) == 1 || check_meals(r) == 1)
			break ;
	}
	return (r);
}
