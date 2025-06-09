/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:39 by samperez          #+#    #+#             */
/*   Updated: 2025/06/09 13:37:48 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
}			t_philo;

typedef struct s_rules
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_must_eat;
}			t_rules;

// Argv parsing
int		check_params(int argc, char **argv);
char	*ft_itoa(int n);
long	ft_atol(const char *nptr);

// Init functions
int		init_rules(t_rules *rules, t_philo *philo, char **argv, int argc);
int		init_philos(t_rules *rules, t_philo *philo);

// Error / free
void	free_all(t_rules *rules, t_philo *philo);

#endif