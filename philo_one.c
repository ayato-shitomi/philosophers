/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:33:06 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/31 08:33:06 by ashitomi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	*p_thread_one(void *void_philo)
{
	(void)void_philo;
	return (NULL);
}

int	philo_one(t_rules *rules)
{
	t_philo		*phi;
	long long	death;

	phi = rules->philo;
	rules->first_timestamp = ft_timestamp();
	if (pthread_create(&(phi[0].thread_id), NULL, p_thread_one, &(phi[0])))
		return (1);
	make_sleep(rules->time_to_deth, rules);
	death = ft_timestamp();
	printf("%lli\t", death - rules->first_timestamp);
	printf("%d died\n", 1);
	rules->dieded = 1;
	exit_launcher(rules, phi);
	return (0);
}
