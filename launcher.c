/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/24 20:45:27 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	philo_eats(t_philo *philo)
{
	t_rules	 *rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->l_fork_id]));
	print_act(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->r_fork_id]));
	print_act(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	print_act(rules, philo->id, "is eating");
	philo->t_last_meal = ft_timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	make_sleep(rules->time_to_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->l_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->r_fork_id]));
}

void	*p_thread(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->dieded))
	{
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		print_act(rules, philo->id, "is sleeping");
		make_sleep(rules->time_to_sleep, rules);
		print_act(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	death_checker(t_rules *r, t_philo *p)
{
	int	i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, ft_timestamp()) > r->time_to_deth)
			{
				print_act(r, i, "died");
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

void	exit_launcher(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

int	launcher(t_rules *rules)
{
	int		i;
	t_philo	*phi;

	i = 0;
	phi = rules->philo;
	rules->first_timestamp = ft_timestamp();
	if (rules->nb_philo == 1)
		return (philo_one(rules));
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = ft_timestamp();
		i++;
	}
	death_checker(rules, rules->philo);
	exit_launcher(rules, phi);
	return (0);
}
