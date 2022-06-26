/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utl_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:43:33 by ydahni            #+#    #+#             */
/*   Updated: 2022/04/06 22:35:28 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_fork(t_philo *philo, char **av)
{
	int				i;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*printf2;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	printf2 = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(printf2, NULL);
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].forks = fork;
		philo[i].print = printf2;
		i++;
	}
	return (philo);
}

t_philo	*philo_init(int ac, char **av, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].number_of_philosophers = ft_atoi(av[1]);
		philo[i].start_time = gettime();
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].if_true = 1;
		philo[i].num_of_eat = 0;
		philo[i].last_time_eat = gettime();
		philo[i].ac = ac;
		philo[i].nb_of_times_each_philo_must_eat = -1;
		if (ac == 6)
			philo[i].nb_of_times_each_philo_must_eat = ft_atoi(av[5]);
		philo[i].index = i;
		i++;
	}
	return (philo);
}

void	check_die(t_philo *philo)
{
	int	i;
	int	j;

	j = 0;
	while (j < philo->number_of_philosophers
		|| philo->nb_of_times_each_philo_must_eat == -1)
	{
		i = 0;
		j = 0;
		while (i < philo->number_of_philosophers)
		{
			if (gettime() - philo[i].last_time_eat >= philo->time_to_die)
			{
				pthread_mutex_lock(philo->print);
				printf("\033[0;31m%04lld %d died\033[0m\n",
					gettime() - philo[i].start_time, philo[i].index + 1);
				return ;
			}
			if (philo[i].num_of_eat >= philo->nb_of_times_each_philo_must_eat)
				j++;
			i++;
		}
	}
}

long long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long sleep)
{
	long long	time;

	time = gettime();
	while ((gettime() - time) < sleep)
	{
		usleep(100);
	}
}
