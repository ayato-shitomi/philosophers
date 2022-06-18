/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:13 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (0 <= --i)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philo(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].l_fork_id = i;
		rules->philo[i].r_fork_id = (i + 1) % rules->nb_philo;
		rules->philo[i].t_last_meal = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	init_all(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_basic_atoi(argv[1]);
	rules->time_to_deth = ft_basic_atoi(argv[2]);
	rules->time_to_eat = ft_basic_atoi(argv[3]);
	rules->time_to_sleep = ft_basic_atoi(argv[4]);
	rules->all_ate = 0;
	rules->dieded = 0;
	if (rules->nb_philo < 2 || 200 < rules->nb_philo)
		return (2);
	if (rules->time_to_deth < 0 || rules->time_to_eat < 0
		|| rules->time_to_sleep < 0)
		return (3);
	if (argv[5])
	{
		rules->nb_eat = ft_basic_atoi(argv[5]) - 1;
		if (rules->nb_eat <= -1)
			return (4);
	}
	else
		rules->nb_eat = -1;
	if (init_mutex(rules))
		return (10);
	init_philo(rules);
	return (0);
}
