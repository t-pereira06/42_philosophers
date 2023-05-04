/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:35:05 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/04 14:48:29 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include <sys/time.h>

//Error
# define ALLOC_ERR_1 "Eror while allocating ID's"
# define ALLOC_ERR_3 "Eror while allocating philos"
# define ALLOC_ERR_2 "Eror while allocating forks"
//	Input errors
# define ERR_IN_1 "Invalid input character"
# define ERR_IN_2 "Invalid input values"
//	Thread errors
# define TH_ERR "Error creating threads"
# define JOIN_ERR "Error joining threads"
# define INIT_ERR_1 "Error initing forks"
//	Philo errors
# define TAKE_FORK "has taken a fork 🍴"
# define THINKING "is thinking 🤔"
# define SLEEPING "is sleeping 💤"
# define EATING "is eating 🍲"
# define DIED "died ☠️"

//Philosopher struct
typedef	struct	philo
{
	int				id;
	long long		last_meal;
	int				times_eaten;
	pthread_t		philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct rules	*rules;
}				t_philo;

//Rules struct
typedef struct rules
{
	int	num_p;
	int	ttd;
	int	tte;
	int	tts;
	int	tme;
	t_philo	*philos;
	pthread_mutex_t	*forks;
}				t_rules;

//libft_functions.c
int	ft_isdigit(int a);
int	ft_atoi(char *str);

//creating.c
pthread_mutex_t	*forks(t_rules *rules);
t_philo			*philosophers(t_rules *rules, pthread_mutex_t *forks);
void			create_philos_threads(t_rules *rules);
void			create_philos_and_forks(t_rules *rules);

//utils.c
long long	gettime(void);
void	print_message(char *message, int fd);

#endif

