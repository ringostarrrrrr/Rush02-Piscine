/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:43:43 by takokamo          #+#    #+#             */
/*   Updated: 2022/05/08 20:48:21 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*cut_space_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	return (&str[i]);
}

int	cut_space_key(char *str)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}
