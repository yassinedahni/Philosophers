/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:35:41 by ydahni            #+#    #+#             */
/*   Updated: 2022/06/25 19:38:50 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%04lld %d %s\n",
		gettime() - philo->start_time, philo->index + 1, str);
	pthread_mutex_unlock(philo->print);
}

void	norm_1(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->index]);
	print("has taken a fork", philo);
	pthread_mutex_lock(&philo->forks[(philo->index + 1)
		% philo->number_of_philosophers]);
	print("has taken a fork", philo);
	philo->last_time_eat = gettime();
	print("is eating", philo);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock (&philo->forks[philo->index]);
	pthread_mutex_unlock (&philo->forks[(philo->index + 1)
		% philo->number_of_philosophers]);
}

void	norm_2(t_philo *philo)
{
	print("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
	print("is thinking", philo);
}

void	*philo_thread(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	while (1)
	{
		norm_1(philo);
		if (philo->ac == 6)
			philo->num_of_eat++;
		if (philo->num_of_eat >= philo->nb_of_times_each_philo_must_eat
			&& philo->nb_of_times_each_philo_must_eat != -1)
			break ;
		norm_2(philo);
	}
	return (0);
}
