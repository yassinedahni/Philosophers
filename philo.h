/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:28:33 by ydahni            #+#    #+#             */
/*   Updated: 2022/06/25 19:38:56 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	long long		last_time_eat;
	long long		start_time;
	long long		time_to_eat;
	int				nb_of_times_each_philo_must_eat;
	int				number_of_philosophers;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_eat;
	int				if_true;
	int				index;
	int				ac;
}	t_philo;

t_philo		*philo_init(int ac, char **av, t_philo *philo);
t_philo		*ft_fork(t_philo *philo, char **av);
void		creation_thread(int ac, char **av, t_philo *philo);
void		ft_usleep(long long sleep);
void		check_die(t_philo *philo);
long long	gettime(void);
int			check(int ac, char **av);
int			check_char(char *av);
int			ft_atoi(char *str);
int			error(int ac);

//philo_thread
void		print(char *str, t_philo *philo);
void		norm_1(t_philo *philo);
void		norm_2(t_philo *philo);
void		*philo_thread(void *p);

#endif