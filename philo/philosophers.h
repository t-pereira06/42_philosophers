/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:35:05 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/17 09:28:36 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

//	Philo outputs
# define TAKE_FORK "has taken a fork\n"
# define THINKING "is thinking\n"
# define SLEEPING "is sleeping\n"
# define EATING "is eating\n"
# define DIED "died\n"

//Philosopher struct
typedef struct philo
{
	int				id;
	long long		last_meal;
	int				times_eaten;
	pthread_mutex_t	hold_death;
	pthread_t		philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct rules	*rules;
}				t_philo;

//Rules struct
typedef struct rules
{
	int				num_p;
	int				ttd;
	int				tte;
	int				tts;
	int				t_each_must_eat;
	long long		time_start;
	int				all_ate;
	int				phi_dead;
	pthread_mutex_t	verification;
	pthread_mutex_t	print;
	pthread_t		monitoring;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}				t_rules;

//libft_functions.c
int				ft_isdigit(int a);
int				ft_atoi(char *str);
long			ft_atol(char *str);

//creating.c
pthread_mutex_t	*forks(t_rules *rules);
t_philo			*philosophers(t_rules *rules, pthread_mutex_t *forks);
void			create_philos_threads(t_rules *rules);
void			create_philos_and_forks(t_rules *rules);

//utils.c
long long		gettime(void);
void			print_message(char *message, int fd);
void			print_terminal(t_philo *philo, char *message);
int				one_philo(t_philo *philo);

//running.c
int				grab_forks(t_philo *philo);
int				eating(t_philo *philo);
int				sleeping(t_philo *philo);
int				thinking(t_philo *philo);
void			*running(void *index);

//monitoring.c
int				num_philos_dead(t_rules *rules);
int				num_philos_eaten(t_rules *rules);
void			*monitoring(void *index);

#endif