/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:14:48 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/15 19:42:46 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

void	ft_free(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	free(table->forks);
}

int	is_dead(t_table *table)
{
	int	is_dead;

	is_dead = 0;
	pthread_mutex_lock(&table->dead_lock);
	is_dead = table->dead;
	pthread_mutex_unlock(&table->dead_lock);
	return (is_dead);
}

void	print_message(t_table *table, int id, char *msg)
{
	long long	time;

	pthread_mutex_lock(&table->dead_lock);
	if (table->dead == 0)
	{
		pthread_mutex_unlock(&table->dead_lock);
		pthread_mutex_lock(&table->print_lock);
		time = get_time() - table->start_ms;
		printf("%lld %d %s\n", time, id, msg);
		pthread_mutex_unlock(&table->print_lock);
	}
	else
		pthread_mutex_unlock(&table->dead_lock);
}

int	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(500);
	return (0);
}
