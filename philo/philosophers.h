/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:35:05 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/02 16:52:44 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef	struct	philo
{
	int				id;
	long long		last_meal;
	int				times_eaten;
	pthread_t		philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_rules	*rules;
}				t_philo;

typedef struct rules
{
	int	num_p;
	int	ttd;
	int	tte;
	int	tts;
	int	tme;
}				t_rules;

//libft_functions.c
int	ft_isdigit(int a);
int	ft_atoi(char *str);

#endif

