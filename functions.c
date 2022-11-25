/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:13:39 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 20:48:30 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*ft_strcat_space(char *ans, char *value)
{
	while (*value != '\0')
	{
		*ans = *value;
		ans++;
		value++;
	}
	*ans = ' ';
	return (ans + 1);
}

char	*ft_delete_lastspace(char *ans)
{
	char	*top;

	top = ans;
	while (*ans != '\0')
	{
		if (*ans == ' ' && *(ans + 1) == '\0')
		{
			*ans = '\0';
		}
		ans++;
	}
	return (top);
}

unsigned int	ft_power(unsigned int nb, unsigned int power)
{
	unsigned int	result;

	result = 1;
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		result = result * nb * ft_power(nb, power - 1);
		return (result);
	}
}

void	display(char *ans)
{
	while (*ans != '\0')
	{
		write(1, ans, 1);
		ans++;
	}
}

void	ifzero(unsigned int n, char *ans, t_dict dict[])
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (dict[i].value != '\0')
		{
			if (dict[i].key == 0)
			{
				ft_strcat_space(ans, dict[i].value);
			}
			i++;
		}
	}
}
