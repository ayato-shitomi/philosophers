#include "./includes/philo.h"

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
	usleep(rules->time_to_deth*1000);
	printf("%lli\t", ft_timestamp() - rules->first_timestamp);
	printf("%d died\n", 1);
	rules->dieded = 1;
	exit_launcher(rules, phi);
	return (0);
}
