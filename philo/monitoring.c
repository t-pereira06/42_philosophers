/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:03:12 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/15 10:31:33 by tsodre-p         ###   ########.fr       */
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
		pthread_mutex_lock(&rules->hold_verification);
		if ((gettime() - rules->philos[i].last_meal) > rules->ttd)
		{
			print_terminal(&rules->philos[i], DIED);
			rules->phi_dead = 1;
			return (1);
		}
		pthread_mutex_unlock(&rules->hold_verification);
		i++;
	}
	return (0);
}

//Check if all philos have eaten
int	num_philos_eaten(t_rules *rules)
{
	pthread_mutex_lock(&rules->hold_verification);
	if (rules->count_eat == rules->num_p)
	{
		pthread_mutex_unlock(&rules->hold_verification);
		return (1);
	}
	pthread_mutex_unlock(&rules->hold_verification);
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
