#include "includes/philo.h"

static void	*p_thread_one(void *void_philo)
{
	(void)void_philo;
	return (NULL);
}

int	philo_one(t_rules *rules)
{
	t_philo *phi;

	phi = rules->philo;
	rules->first_timestamp = ft_timestamp();
	if (pthread_create(&(phi[0].thread_id), NULL, p_thread_one, &(phi[0])))
		return (1);
	death_checker(rules, rules->philo);
	exit_launcher(rules, phi);
	return (0);
}
