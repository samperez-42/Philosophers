/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:04 by samperez          #+#    #+#             */
/*   Updated: 2025/06/09 13:37:39 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	*philo;

	if (check_params(argc, argv))
		return (EXIT_FAILURE);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (printf("Error: Malloc failed\n"), EXIT_FAILURE);
	philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	if (!philo)
	{
		free(rules);
		return (printf("Error: Malloc failed\n"), EXIT_FAILURE);
	}
	if (init_rules(rules, philo, argv, argc))
		return (printf("Failed to init the struct\n"), EXIT_FAILURE);
	if (init_philos(rules, philo))
		return (printf("Failed to init the philosophers\n"), EXIT_FAILURE);
	free_all(rules, philo);
	return (EXIT_SUCCESS);
}
