/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:04 by samperez          #+#    #+#             */
/*   Updated: 2025/09/03 18:34:37 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*r;

	if (check_params(argc, argv))
		return (EXIT_FAILURE);
	r = malloc(sizeof(t_rules));
	if (!r)
		return (printf("Error: Malloc failed\n"), EXIT_FAILURE);
	if (init_struct(r, argv, argc))
		return (printf("Failed to init the r struct\n"), EXIT_FAILURE);
	if (init_philos(r, 0))
		return (printf("Failed to init the philosophers\n"), EXIT_FAILURE);
	if (threads(r))
		return (printf("Failed to init the threads\n"), EXIT_FAILURE);
	destroy_mutex(r);
	free_all(r);
	return (EXIT_SUCCESS);
}
