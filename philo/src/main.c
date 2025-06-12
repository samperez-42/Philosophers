/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:04 by samperez          #+#    #+#             */
/*   Updated: 2025/06/12 11:16:42 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (check_params(argc, argv))
		return (EXIT_FAILURE);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (printf("Error: Malloc failed\n"), EXIT_FAILURE);
	if (init_struct(rules, argv, argc))
		return (printf("Failed to init the rules struct\n"), EXIT_FAILURE);
	if (init_threads(rules))
		return (printf("Failed to init the threads\n"), EXIT_FAILURE);
	destroy_mutex(rules);
	free_all(rules);
	return (EXIT_SUCCESS);
}
