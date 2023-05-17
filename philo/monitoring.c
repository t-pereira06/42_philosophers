/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:03:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/17 12:30:01 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*Check if a philo had died according to the time difference
to the last meal and time_to_die*/
int	num_philos_dead(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->num_p)
	{
		pthread_mutex_lock(&rules->philos[i].hold_death);
		if ((gettime() - rules->philos[i].last_meal) > rules->ttd)
		{
			print_terminal(&rules->philos[i], DIED);
			pthread_mutex_lock(&rules->verification);
			rules->phi_dead = 1;
			pthread_mutex_unlock(&rules->verification);
			pthread_mutex_unlock(&rules->philos[i].hold_death);
			return (1);
		}
		pthread_mutex_unlock(&rules->philos[i].hold_death);
		i++;
	}
	return (0);
}

//Check if all philos have eaten
int	num_philos_eaten(t_rules *rules)
{
	if (rules->t_each_must_eat == 0)
		return (0);
	pthread_mutex_lock(&rules->verification);
	if (rules->all_ate == rules->num_p)
	{
		pthread_mutex_unlock(&rules->verification);
		return (1);
	}
	pthread_mutex_unlock(&rules->verification);
	return (0);
}

/*Monitor the program, checking if there is a philo dead
and if all philos ate*/
void	*monitoring(void *index)
{
	t_rules *rules;

	rules = (t_rules *)index;
	while (1)
	{
		if (num_philos_dead(rules))
			return (NULL);
		if (num_philos_eaten(rules))
			return (NULL);
	}	
}
