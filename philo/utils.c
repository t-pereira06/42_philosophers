/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:26:01 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/16 14:46:34 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Function to get time from computer
long long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

//Function to print a string
void	print_message(char *s, int fd)
{
	int		i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*Function to print a output in the terminal like
the subject asks*/
void	print_terminal(t_philo *philo, char *message)
{
	long long	time;

	pthread_mutex_lock(&philo->rules->verification);
	if (philo->rules->phi_dead
		|| philo->rules->all_ate == philo->rules->num_p)
	{
		pthread_mutex_unlock(&philo->rules->verification);
		return ;
	}
	pthread_mutex_lock(&philo->rules->verification);
	time = gettime() - philo->rules->time_start;
	pthread_mutex_lock(&philo->rules->print);
	printf("%lld %d %s", time, philo->id, message);
	pthread_mutex_unlock(&philo->rules->print);
}

/*Function like atoi but for long numbers.
Used in check_args*/
long	ft_atol(char *str)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
