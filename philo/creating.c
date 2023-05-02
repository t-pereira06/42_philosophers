/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:30:09 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/02 16:56:33 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	*create_forks(t_rules *rules)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * rules->num_p);
	while(i < rules->num_p)
	{
		if(pthread_mutex_init(&forks[i], NULL) != 0)
			write(1, "Couldn't start mutex!", 22);
		i++;
	}
	return(forks);
}
