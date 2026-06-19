/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:58:16 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/15 20:55:38 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_dead(t_table *table)
{
	pthread_mutex_lock(&table->dead_lock);
	table->dead = 1;
	pthread_mutex_unlock(&table->dead_lock);
}

static int	first_condition(t_table *table, t_philo *philo,
		int i, long long time)
{
	long long	now;

	now = get_time();
	if (now - time > table->t_die)
	{
		print_message(table, philo[i].id, "#######died#######");
		set_dead(table);
		return (1);
	}
	return (0);
}

static int	add_eat(t_table *table, int meals, int f_eat)
{
	if (meals >= table->must_eat
		&& table->must_eat > 0)
		return (f_eat + 1);
	return (f_eat);
}

static int	second_condition(t_table *table, int f_eat)
{
	if (f_eat == table->n_philo)
	{
		set_dead(table);
		return (1);
	}
	return (0);
}

void	monitor(t_table *table, t_philo *philo)
{
	long long	time;
	int			i;
	int			f_eat;
	int			meals;

	while (!is_dead(table))
	{
		f_eat = 0;
		i = 0;
		while (i < table->n_philo)
		{
			pthread_mutex_lock(&table->meal_lock);
			meals = philo[i].meals_eaten;
			time = philo[i].last_meal_ms;
			pthread_mutex_unlock(&table->meal_lock);
			f_eat = add_eat(table, meals, f_eat);
			if (first_condition(table, philo, i, time)
				|| second_condition(table, f_eat))
				return ;
			i++;
		}
		ft_usleep(1);
	}
}
