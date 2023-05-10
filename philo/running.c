/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:02:57 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/10 12:25:45 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Function to grab forks to eat
int	grab_forks(t_philo *philo)
{
	if (philo->rules->phi_dead
		|| philo->rules->count_eat == philo->rules->num_p)
		return (0);
	if (pthread_mutex_lock(philo->l_fork) != 0)
		return (0);
	print_terminal(philo, TAKE_FORK);
	if (pthread_mutex_lock(philo->r_fork) != 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (0);
	}
	print_terminal(philo, TAKE_FORK);
	return (1);
}

//Function to make philosopher eat
int	eating(t_philo *philo)
{
	if (philo->rules->phi_dead
		|| philo->rules->count_eat == philo->rules->num_p)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	pthread_mutex_lock(philo->hold_death);
	print_terminal(philo, EATING);
	philo->last_meal = gettime();
	philo->times_eaten++;
	if (philo->rules->t_each_must_eat >= 0)
	{
		if (philo->times_eaten == philo->rules->t_each_must_eat)
			philo->rules->t_each_must_eat++;
	}
	usleep(philo->rules->tte * 1000);
	pthread_mutex_unlock(philo->hold_death);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (1);
}

//Function to make philosopher sleep
int	sleeping(t_philo *philo)
{
	if (philo->rules->phi_dead
		|| philo->rules->count_eat == philo->rules->num_p)
		return (0);
	print_terminal(philo, SLEEPING);
	usleep(philo->rules->tts * 1000);
	return (1);
}

//Function to make philosopher think
int	thinking(t_philo *philo)
{
	if (philo->rules->phi_dead
		|| philo->rules->count_eat == philo->rules->num_p)
		return (0);
	print_terminal(philo, THINKING);
	return (1);
}

/*Function to run the program, calling the task functions created
for the philosophers*/
void	*running(void *index)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)philo;
	if (philo->rules->num_p == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		return NULL;
	}
	if(philo->id % 2 != 0)
		usleep(1000);
	while (1)
	{
		if(grab_forks(philo))
			return NULL;
		if(eating(philo))
			return NULL;
		if(sleeping(philo))
			return NULL;
		if(thinking(philo))
			return NULL;
	}
}
