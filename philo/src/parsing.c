/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:19:35 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/14 20:58:51 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_my_atoi(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)num);
}

static void	start_parsing(char *argv[])
{
	int	num_philos;

	if (check_arg(argv[1]) == 1)
	{
		printf("Error: Invalid number of philosophers\n");
		exit(1);
	}
	num_philos = ft_my_atoi(argv[1]);
	if (num_philos < 1 || num_philos > PHILO_MAX)
	{
		printf("Error: Invalid number of philosophers\n");
		exit(1);
	}
	if (check_arg(argv[2]) == 1 || ft_my_atoi(argv[2]) <= 0)
	{
		printf("Error: Invalid time to die\n");
		exit(1);
	}
}

void	ft_parsing(int argc, char *argv[])
{
	start_parsing(argv);
	if (check_arg(argv[3]) == 1 || ft_my_atoi(argv[3]) <= 0)
	{
		printf("Error: Invalid time to eat\n");
		exit(1);
	}
	if (check_arg(argv[4]) == 1 || ft_my_atoi(argv[4]) <= 0)
	{
		printf("Error: Invalid time to sleep\n");
		exit(1);
	}
	if (argc == 6)
	{
		if (check_arg(argv[5]) == 1 || ft_my_atoi(argv[5]) <= 0)
		{
			printf("Error: Invalid times of each philosophers must eat\n");
			exit(1);
		}
	}
}
