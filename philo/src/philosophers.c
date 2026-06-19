/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:02:10 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/15 20:55:53 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = philo->table;
	while (!is_dead(table))
	{
		r_think(table, philo);
		if (table->n_philo == 1)
		{
			pthread_mutex_lock(&table->forks[philo->left_fork]);
			print_message(table, philo->id, "has taken a fork");
			ft_usleep(table->t_die);
			pthread_mutex_unlock(&table->forks[philo->left_fork]);
			return (NULL);
		}
		r_take_forks(table, philo);
		r_eat(table, philo);
		r_drop_forks(table, philo);
		r_sleep(table, philo);
	}
	return (NULL);
}

int	create_threads(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
		{
			while (i > 0)
			{
				pthread_join(philo[i - 1].thread, NULL);
				i--;
			}
			return (1);
		}
		i++;
	}
	monitor(table, philo);
	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	table;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		ft_parsing(argc, argv);
		ft_init_table(&table, argc, argv);
		philo = malloc(sizeof(t_philo) * table.n_philo);
		if (!philo)
		{
			ft_free(&table);
			exit(1);
		}
		ft_init_philo(philo, &table);
		create_threads(philo, &table);
		ft_free(&table);
		free(philo);
	}
	else
		printf("Error: invalid number of arguments\n");
	return (0);
}
