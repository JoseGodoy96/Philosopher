/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:58:23 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/15 20:55:22 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	r_think(t_table *table, t_philo *philo)
{
	print_message(table, philo->id, "is thinking");
	ft_usleep(1);
}

void	r_take_forks(t_table *table, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_message(table, philo->id, "has taken a fork");
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_message(table, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		print_message(table, philo->id, "has taken a fork");
		pthread_mutex_lock(&table->forks[philo->left_fork]);
		print_message(table, philo->id, "has taken a fork");
	}
}

void	r_drop_forks(t_table *table, t_philo *philo)
{
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	r_eat(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->meal_lock);
	philo->last_meal_ms = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&table->meal_lock);
	print_message(table, philo->id, "is eating");
	ft_usleep(table->t_eat);
}

void	r_sleep(t_table *table, t_philo *philo)
{
	print_message(table, philo->id, "is sleeping");
	ft_usleep(table->t_sleep);
}
