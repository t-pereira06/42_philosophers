/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:30:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/17 12:39:42 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Function to create the forks for philosophers to eat
pthread_mutex_t	*forks(t_rules *rules)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * rules->num_p);
	while (i < rules->num_p)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

//Function to create the philosophers
t_philo	*philosophers(t_rules *rules, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	rules->philos = malloc(sizeof(t_philo) * rules->num_p);
	while (i < rules->num_p)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].last_meal = gettime();
		rules->philos[i].times_eaten = 0;
		rules->philos[i].l_fork = &forks[i];
		if (i == rules->num_p - 1)
			rules->philos[i].r_fork = &forks[0];
		else
			rules->philos[i].r_fork = &forks[i + 1];
		rules->philos[i].rules = rules;
		pthread_mutex_init(&rules->philos[i].hold_death, NULL);
		i++;
	}
	return (rules->philos);
}

//Function to create threads for philosophers
void	create_philos_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->num_p)
	{
		pthread_create(&rules->philos[i].philo,
			NULL, &running, &rules->philos[i]);
		usleep(2000);
		i++;
	}
	pthread_create(&rules->monitoring, NULL, &monitoring, rules);
}

//Function to join thread and destroy mutexes
void	join_threads_and_destroy_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->num_p)
	{
		pthread_join(rules->philos[i].philo, NULL);
		i++;
	}
	i = 0;
	pthread_join(rules->monitoring, NULL);
	while (i < rules->num_p)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&rules->philos[i].hold_death);
		i++;
	}
	pthread_mutex_destroy(&rules->print);
}

void	create_philos_and_forks(t_rules *rules)
{
	rules->forks = forks(rules);
	pthread_mutex_init(&rules->print, NULL);
	pthread_mutex_init(&rules->verification, NULL);
	philosophers(rules, rules->forks);
	create_philos_threads(rules);
	join_threads_and_destroy_mutex(rules);
}
