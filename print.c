/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:13 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	err_zero_to_nine(int n)
{
	if (n == 1)
		printf("Number of arguments is invalid.");
	else if (n == 2)
		printf("`number_of_philosophers` is invalid.");
	else if (n == 3)
	{
		printf("Something is wrong with `time_to_die`, ");
		printf("`time_to_eat` or `time_to_sleep`.");
	}
	else if (n == 4)
		printf("`number_of_times_each_philosopher_must_eat` is invalid.");
	usage();
}

void	err_ten_to_nineteen(int n)
{
	if (n == 10)
		printf("Something is wrong when init mutex at `init_mutex()`.");
	else if (n == 11)
		printf("There was an error creating the threads.");
	return ;
}

int	err_hub(int n)
{
	printf("ERROR %d : ", n);
	if (0 <= n && n < 10)
		err_zero_to_nine(n);
	else if (10 <= n && n < 20)
		err_ten_to_nineteen(n);
	printf("\n");
	return (1);
}

void	print_act(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->dieded))
	{
		printf("%lli\t", ft_timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}
