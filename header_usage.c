/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:13 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	header(void)
{
	printf("\n  ________  ___  ___  ___  ___       ________      \n");
	printf(" |\\   __  \\|\\  \\|\\  \\|\\  \\|\\  \\     |\\   __  \\     \n");
	printf(" \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\ \\  \\    \\ \\  \\|\\  \\    \n");
	printf("  \\ \\   ____\\ \\   __  \\ \\  \\ \\  \\    \\ \\  \\\\\\  \\   \n");
	printf("   \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\ \\  \\____\\ \\  \\\\\\  \\  \n");
	printf("    \\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\_______\\ \\_______\\ \n");
	printf("     \\|__|     \\|__|\\|__|\\|__|\\|_______|\\|_______| \n");
}

void	usage(void)
{
	header();
	printf("\n./philo [number_of_philosophers] [time_to_die]");
	printf("[time_to_eat time_to_sleep] ");
	printf("[number_of_times_each_philosopher_must_eat]\n\n");
	printf("number_of_philosophers: ");
	printf("The number of philosophers and also the number of forks.\n");
	printf("time_to_die (in milliseconds): ");
	printf("If a philosopher didn’t start eating time_to_die milliseconds");
	printf("since the beginning of their last meal or the beginning of ");
	printf("the simulation, they die.\n");
	printf("time_to_eat (in milliseconds): ");
	printf("The time it takes for a philosopher to eat.");
	printf("During that time, they will need to hold two forks.\n");
	printf("time_to_sleep (in milliseconds): ");
	printf("The time a philosopher will spend sleeping.\n");
	printf("number_of_times_each_philosopher_must_eat (optional argument): ");
	printf("If all philosophers have eaten at least number_of_times_");
	printf("each_philosopher_must_eat times, the simulation stops.");
	printf("If not specified, the simulation stops when a philosopher dies.\n");
}
