/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:02:57 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/17 12:35:40 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Function to grab forks to eat
int	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->verification);
	if (philo->rules->phi_dead == 1
		|| philo->rules->all_ate == philo->rules->num_p)
	{
		pthread_mutex_unlock(&philo->rules->verification);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->verification);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_terminal(philo, TAKE_FORK);
		pthread_mutex_lock(philo->l_fork);
		print_terminal(philo, TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_terminal(philo, TAKE_FORK);
		pthread_mutex_lock(philo->r_fork);
		print_terminal(philo, TAKE_FORK);
	}
	return (0);
}

//Function to make philosopher eat
int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->verification);
	if (philo->rules->phi_dead == 1
		|| (philo->rules->all_ate == philo->rules->num_p))
	{
		pthread_mutex_unlock(&philo->rules->verification);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->verification);
	pthread_mutex_lock(&philo->hold_death);
	print_terminal(philo, EATING);
	philo->last_meal = gettime();
	pthread_mutex_lock(&philo->rules->verification);
	philo->times_eaten++;
	if (philo->rules->t_each_must_eat != 0)
		if (philo->times_eaten == philo->rules->t_each_must_eat)
			philo->rules->all_ate++;
	pthread_mutex_unlock(&philo->rules->verification);
	pthread_mutex_unlock(&philo->hold_death);
	usleep(philo->rules->tte * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

//Function to make philosopher sleep
int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->verification);
	if (philo->rules->phi_dead == 1
		|| philo->rules->all_ate == philo->rules->num_p)
	{
		pthread_mutex_unlock(&philo->rules->verification);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->verification);
	print_terminal(philo, SLEEPING);
	usleep(philo->rules->tts * 1000);
	return (0);
}

//Function to make philosopher think
int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->verification);
	if (philo->rules->phi_dead == 1
		|| philo->rules->all_ate == philo->rules->num_p)
	{
		pthread_mutex_unlock(&philo->rules->verification);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->verification);
	print_terminal(philo, THINKING);
	return (0);
}

/*Function to run the program, calling the task functions created
for the philosophers*/
void	*running(void *index)
{
	t_philo	*philo;

	philo = (t_philo *)index;
	if (philo->id % 2 == 0)
		usleep(2500);
	while (1)
	{
		if (philo->rules->num_p == 1)
		{
			pthread_mutex_lock(philo->l_fork);
			print_terminal(philo, TAKE_FORK);
			pthread_mutex_unlock(philo->l_fork);
			return (NULL);
		}
		if (grab_forks(philo))
			return (NULL);
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	return (NULL);
}
