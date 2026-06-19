/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:10:35 by jgodoy-m          #+#    #+#             */
/*   Updated: 2026/01/15 19:39:08 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define PHILO_MAX 300

typedef struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	long long		start_ms;
	int				dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
}		t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	long long		last_meal_ms;
	int				meals_eaten;
	t_table			*table;
}		t_philo;

// philosophers.c
void		*routine(void *arg);
int			create_threads(t_philo *philo, t_table *table);

// parsing.c
int			ft_my_atoi(char *str);
void		ft_parsing(int argc, char *argv[]);

// utils.c
long long	get_time(void);
void		ft_free(t_table *table);
int			is_dead(t_table *table);
void		print_message(t_table *table, int id, char *msg);
int			ft_usleep(long long time);

// init.c
void		ft_init_table(t_table *table, int argc, char *argv[]);
void		ft_init_philo(t_philo *philo, t_table *table);

// routine.c
void		r_think(t_table *table, t_philo *philo);
void		r_take_forks(t_table *table, t_philo *philo);
void		r_drop_forks(t_table *table, t_philo *philo);
void		r_eat(t_table *table, t_philo *philo);
void		r_sleep(t_table *table, t_philo *philo);

// monitor.c
void		set_dead(t_table *table);
void		monitor(t_table *table, t_philo *philo);

#endif
