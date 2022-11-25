/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:05:46 by takokamo          #+#    #+#             */
/*   Updated: 2022/05/08 20:49:51 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

unsigned int	ft_strlen_arg(unsigned int argc, char **argv)
{
	unsigned int	i;

	i = 0;
	while (argv[argc - 1][i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

long	ft_atoi_mini(int argc, char **argv)
{
	unsigned int	j;
	long			check_max;
	long			num;

	j = 0;
	num = 0;
	check_max = 0;
	while (argv[argc - 1][j] != '\0')
	{
		check_max = (check_max * 10) + (argv[argc - 1][j] - '0');
		if (check_max > 4294967295)
		{
			ft_putstr("Error\n");
			return (-1);
		}
		j++;
	}
	num = check_max;
	return (num);
}

long	ft_argcheck(int argc, char **argv)
{
	int				j;
	int				input_len;
	long			conv_num;

	input_len = ft_strlen_arg(argc, argv);
	j = 0;
	while (argv[argc - 1][j] <= '9' && argv[argc - 1][j] >= '0')
		j++;
	if (input_len != j)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	if (argv[argc - 1][0] == '0' && argv[argc - 1][1] != '\0')
	{
		ft_putstr("Error\n");
		return (-1);
	}
	conv_num = ft_atoi_mini(argc, argv);
	return (conv_num);
}
