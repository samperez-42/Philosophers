/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:04 by samperez          #+#    #+#             */
/*   Updated: 2025/05/28 16:33:58 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error: Incorrect number of arguments\n"), EXIT_FAILURE);
	if (check_non_numeric(argv))
	{
		printf("Error: Argv contains non numeric and / or negatives\n");
		return (EXIT_FAILURE);
	}
}
