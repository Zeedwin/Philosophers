/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 05:52:53 by jgirard-          #+#    #+#             */
/*   Updated: 2023/04/01 18:16:29 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	badargs(void)
{
	error("\033[91;1mError: Bad Params\n""\033[95;1mUsage:\033[0m./philosophers "
		"\033[92;1mNUMBER_OF_PHILOS TIME_TO_EAT "
		"TIME_TO_DIE TIME_TO_SLEEP \033[93;1mNUMBER_OF_TIMES_PHILOS_EAT");
}

int	print_invalid_arg(void)
{
	badargs();
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int					i;
	unsigned long int	nb;

	if (!(argc == 5 || argc == 6))
	{
		badargs();
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]))
			return (1);
		if (ft_atoi(argv[1]) > 200)
			error("\033[91;1m Exeeded maximum number of philosophers");
		nb = ft_atoi(argv[i]);
		if (argc == 6 && ft_atoi(argv[5]) == 0)
			return (print_invalid_arg());
		if (i == 1 && (nb <= 0 || nb > 200))
			return (print_invalid_arg());
		if (i != 1 && (nb <= 0 || nb > 2147483647))
			return (print_invalid_arg());
		i++;
	}
	return (0);
}

int	digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	long long int		num;
	int					neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}
