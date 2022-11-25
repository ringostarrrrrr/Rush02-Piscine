/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nketa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:42:47 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 18:52:28 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*billion(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	unsigned int	mod;
	char			*p;

	if (n > 999999999)
	{
		mod = n % ft_power(10, 9);
		n = n / ft_power(10, 9);
		p = miketa(n, ans, dict);
		i = 0;
		while (dict[i].value != '\0')
		{
			if (dict[i].key == ft_power(10, 9) && n != 0)
			{
				return (ft_strcat_space(p, dict[i].value));
			}
			i++;
		}
		n = mod;
	}
	return (ans);
}

char	*million(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	unsigned int	mod;
	char			*p;

	if (n > 999999)
	{
		mod = n % ft_power(10, 6);
		n = n / ft_power(10, 6);
		p = miketa(n, ans, dict);
		i = 0;
		while (dict[i].value != '\0')
		{
			if (dict[i].key == ft_power(10, 6) && n % 1000)
			{
				return (ft_strcat_space(p, dict[i].value));
			}
			i++;
		}
		n = mod;
	}
	return (ans);
}

char	*thousand(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	unsigned int	mod;
	char			*p;

	if (n > 999)
	{	
		mod = n % ft_power(10, 3);
		n = n / ft_power(10, 3);
		p = miketa(n, ans, dict);
		i = 0;
		while (dict[i].value != '\0')
		{
			if (dict[i].key == ft_power(10, 3) && n % 1000)
			{
				return (ft_strcat_space(p, dict[i].value));
			}
			i++;
		}
		n = mod;
	}
	return (ans);
}

void	nketa(unsigned int n, t_dict dict[])
{
	char			*ans;
	char			*p1;
	char			*p2;
	char			*p3;
	unsigned int	mod;

	ans = (char *)malloc(sizeof(char) * 2048);
	mod = n % ft_power(10, 3);
	ifzero(n, ans, dict);
	p1 = billion(n, ans, dict);
	p2 = million(n, p1, dict);
	p3 = thousand(n, p2, dict);
	miketa(mod, p3, dict);
	display(ft_delete_lastspace(ans));
}
