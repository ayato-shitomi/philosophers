/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:13 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:13 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	ft_basic_atoi(const char *str)
{
	int	sign;
	int	c;
	int	rtn;

	c = 0;
	sign = 1;
	rtn = 0;
	if (str[c] == '-')
	{
		sign = -1;
		c++;
	}
	while (str[c])
	{
		if ('0' <= str[c] && str[c] <= '9')
			rtn = rtn * 10 + (str[c] - '0');
		else
			return (0);
		c++;
	}
	return (rtn * sign);
}

long long	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = ft_timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, ft_timestamp()) >= time)
			break ;
		usleep(50);
	}
	return ;
}
