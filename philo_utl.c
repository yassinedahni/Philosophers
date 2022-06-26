/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:34:29 by ydahni            #+#    #+#             */
/*   Updated: 2022/06/16 01:46:22 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	unsigned long	r;
	int				i;
	int				c;

	i = 0;
	r = 0;
	c = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			c *= -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (r > 2147483647)
		return (0);
	return (c * r);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

int	check_char(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (av[i])
	{
		if (!check_char(av[i]))
			return (0);
		i++;
	}
	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	error(int ac)
{
	if (ac == 6)
		return (0);
	write (2, "Error\n", 6);
	return (0);
}
