/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:12:17 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/14 20:08:32 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	start_table(t_table	*table, int argc, char *argv[])
{
	table->n_philo = ft_my_atoi(argv[1]);
	table->t_die = ft_my_atoi(argv[2]);
	table->t_eat = ft_my_atoi(argv[3]);
	table->t_sleep = ft_my_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_my_atoi(argv[5]);
	else
		table->must_eat = -1;
	table->start_ms = get_time();
	table->dead = 0;
	if (pthread_mutex_init(&table->dead_lock, NULL))
		exit(1);
	if (pthread_mutex_init(&table->print_lock, NULL))
	{
		pthread_mutex_destroy(&table->dead_lock);
		exit(1);
	}
	if (pthread_mutex_init(&table->meal_lock, NULL))
	{
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->print_lock);
		exit(1);
	}
}

static void	ft_init_forks(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
	{
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->print_lock);
		pthread_mutex_destroy(&table->meal_lock);
		printf("Error: malloc failed\n");
		exit(1);
	}
}

void	ft_init_table(t_table *table, int argc, char *argv[])
{
	int				i;

	i = 0;
	start_table(table, argc, argv);
	ft_init_forks(table);
	while (i < table->n_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			pthread_mutex_destroy(&table->dead_lock);
			pthread_mutex_destroy(&table->print_lock);
			pthread_mutex_destroy(&table->meal_lock);
			while (i > 0)
			{
				pthread_mutex_destroy(&table->forks[i - 1]);
				i--;
			}
			free(table->forks);
			exit(1);
		}
		i++;
	}
}

void	ft_init_philo(t_philo *philo, t_table *table)
{
	int			i;

	i = 0;
	while (i < table->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % table->n_philo;
		philo[i].last_meal_ms = table->start_ms;
		philo[i].meals_eaten = 0;
		philo[i].table = table;
		i++;
	}
}
