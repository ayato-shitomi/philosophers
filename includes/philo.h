/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:04:38 by ashitomi          #+#    #+#             */
/*   Updated: 2022/06/18 19:04:38 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ===========================
//  INCLUDES
// ===========================

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

// ===========================
//  DEFINES
// ===========================

struct	s_rules;
struct	s_philo;

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				l_fork_id;
	int				r_fork_id;
	long long		t_last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_deth;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				dieded;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[201];
	pthread_mutex_t	writing;
	t_philo			philo[201];
}	t_rules;

// ===========================
//  PROTOTYPES
// ===========================

// print.c
void		print_act(t_rules *rules, int id, char *string);
int			err_hub(int n);

// init.c
int			init_all(t_rules *rules, char **argv);

// utils.c
int			ft_basic_atoi(const char *str);
long long	ft_timestamp(void);
long long	time_diff(long long past, long long pres);
void		make_sleep(long long time, t_rules *rules);

// launcher.c
int			launcher(t_rules *rules);
void		exit_launcher(t_rules *rules, t_philo *philo);
void		death_checker(t_rules *r, t_philo *p);

// header_usage.c
void		header(void);
void		usage(void);

// pholo_one.c
int			philo_one(t_rules *rules);

#endif
