/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:58 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/04/27 14:32:24 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
				write (1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	initialize_stacks(t_rules *rules, int argc, char **argv)
{
	rules->num_p = ft_atoi(argv[1]);
	rules->ttd = ft_atoi(argv[2]);
	rules->tte = ft_atoi(argv[3]);
	rules->tts = ft_atoi(argv[4]);
	if (argc == 6)
		rules->tme = ft_atoi(argv[5]);
	else
		rules->tme = 0;
}


void	check_args(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		check_number(argv);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	//initialize_stuct();
}
