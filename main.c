/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:28:20 by ydahni            #+#    #+#             */
/*   Updated: 2022/06/25 19:46:23 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*single_thread(t_philo *philo, pthread_t *thread_1)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		philo[i].last_time_eat = gettime();
		pthread_create(&thread_1[i], NULL, philo_thread, &philo[i]);
		pthread_detach(thread_1[i]);
		i += 2;
	}
	return (philo);
}

t_philo	*double_thread(t_philo *philo, pthread_t *thread_1)
{
	int	i;

	i = 1;
	while (i < philo->number_of_philosophers)
	{
		philo[i].last_time_eat = gettime();
		pthread_create(&thread_1[i], NULL, philo_thread, &philo[i]);
		pthread_detach(thread_1[i]);
		i += 2;
	}
	return (philo);
}

void	creation_thread(int ac, char **av, t_philo *philo)
{
	pthread_t	*thread_1;
	int			i;

	i = 0;
	thread_1 = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (ac == 5 || ac == 6)
	{
		philo = single_thread(philo, thread_1);
		usleep(60);
		philo = double_thread(philo, thread_1);
	}
	free(thread_1);
	check_die(philo);
}

int	main(int ac, char **av)
{
	t_philo		*philo;

	if (!check(ac, av))
		return (error(ac));
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	philo = philo_init(ac, av, philo);
	philo = ft_fork(philo, av);
	creation_thread(ac, av, philo);
	return (0);
}
