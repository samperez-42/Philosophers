/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:39 by samperez          #+#    #+#             */
/*   Updated: 2025/08/22 14:14:11 by samperez         ###   ########.fr       */
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
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t			thrd;
	t_rules				*r;
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
int			init_struct(t_rules *r, char **argv, int argc);
int			init_philos(t_rules *r, int i);
int			threads(t_rules *rule);

// Clock function
uint64_t	get_time_ms(void);

// Util functions
void		ft_usleep(size_t milliseconds);
void		philo_msg(char *s, t_philo *philo);

// Master thread
void		*watcher(void *r);
// Philosophers routine
void		*rtn(void *arg);

// Error / free
int			destroy_mutex(t_rules *r);
int			free_all(t_rules *r);

#endif