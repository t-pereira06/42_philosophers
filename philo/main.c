/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:58 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/05/15 10:56:09 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_rules(t_rules *rules)
{
	printf("Number of philosophers: %d\n", rules->num_p);
	printf("Time to die: %d\n", rules->ttd);
	printf("Time to eat: %d\n", rules->tte);
	printf("Time to sleep: %d\n", rules->tts);
	printf("Times each must eat: %d\n", rules->t_each_must_eat);
}

//Check if all the arguments are numbers
void	check_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write (1, "Not all values are numbers!\n", 29);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

//Start stack with the arguments
void	initialize_struct(t_rules *rules, int argc, char **argv)
{
	rules->num_p = ft_atoi(argv[1]);
	rules->ttd = ft_atoi(argv[2]);
	rules->tte = ft_atoi(argv[3]);
	rules->tts = ft_atoi(argv[4]);
	rules->time_start = gettime();
	rules->count_eat = 0;
	rules->phi_dead = 0;
	if (argc == 6)
		rules->t_each_must_eat = ft_atoi(argv[5]);
	else
		rules->t_each_must_eat = 0;
}

//Check how many are passed to the function
void	check_args(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		check_number(argv);
	else
	{
		write(1, "Check number of arguments!\n", 28);
		exit(0);
	}
}

//Main function of the program
int	main(int argc, char **argv)
{
	t_rules	*rules;

	check_args(argc, argv);
	rules = malloc(sizeof(rules));
	initialize_struct(rules, argc, argv);
	create_philos_and_forks(rules);
	free(rules->philos);
	free(rules->forks);
	free(rules);
}
