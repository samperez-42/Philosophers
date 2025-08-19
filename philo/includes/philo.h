/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:39 by samperez          #+#    #+#             */
/*   Updated: 2025/08/19 21:18:25 by samperez         ###   ########.fr       */
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
# include <stdint.h>

/*--------------------------------STRUCTS--------------------------------*/

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	int					id;
	int					is_eating;
	int					times_eaten;
	int					last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thrd;
	t_rules				*rules;
}			t_philo;

typedef struct s_rules
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				n_philo;
	size_t			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_must_eat;
}			t_rules;

/*--------------------------------FUNCTIONS--------------------------------*/

// Argv parsing
int			check_params(int argc, char **argv);
char		*ft_itoa(int n);
long		ft_atol(const char *nptr);

// Initializing
int			init_struct(t_rules *rules, char **argv, int argc);
int			init_threads(t_rules *rules);

// Clock function
uint64_t	get_time_ms(void);

// Util functions
void		ft_usleep(size_t milliseconds);
void		philo_msg(char *s, t_philo *philo);

//Philosophers routine
void		*routine(void *arg);

// Error / free
void		destroy_mutex(t_rules *rules);
int			free_all(t_rules *rules);

#endif