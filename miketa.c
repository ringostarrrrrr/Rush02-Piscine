/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miketa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takokamo <takokamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:26:31 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 22:20:03 by takokamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*nhundred(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	char			*p1;

	n = n / 100;
	i = 0;
	if (n != 0)
	{
		while (dict[i++].value != '\0')
		{
			if (n == dict[i].key)
			{
				p1 = ft_strcat_space(ans, dict[i].value);
				i = 0;
				while (dict[i++].value != '\0')
				{
					if (dict[i].key == 100)
						return (ft_strcat_space(p1, dict[i].value));
				}
				ft_putstr("Dict Error");
			}
		}
		ft_putstr("Dict Error");
	}
	return (ans);
}

char	*niketa1(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	char			*p;

	if (0 < n && n <= 20)
	{
		i = 0;
		while (dict[i].value != '\0')
		{
			if (dict[i].key == n)
			{
				p = ft_strcat_space(ans, dict[i].value);
				return (p);
			}
			i++;
		}
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (ans);
}

char	*niketa2(unsigned int n, char *ans, t_dict dict[])
{
	unsigned int	i;
	unsigned int	mod;
	char			*p;

	if (21 <= n && n <= 99)
	{
		mod = n % 10;
		n = n / 10;
		n = n * 10;
		i = 0;
		while (dict[i].value != '\0')
		{
			if (dict[i].key == n)
			{
				p = ft_strcat_space(ans, dict[i].value);
				return (niketa1(mod, p, dict));
			}
			i++;
		}
		ft_putstr("Dict Error\n");
		return (0);
	}
	return (ans);
}

char	*miketa(unsigned int n, char *ans, t_dict dict[])
{
	char			*p1;
	char			*p2;
	char			*p3;
	unsigned int	mod;

	n = n % 1000;
	mod = n % 100;
	n = n / 100;
	n = n * 100;
	p1 = nhundred(n, ans, dict);
	if (p1 == 0)
		return (0);
	p2 = niketa1(mod, p1, dict);
	if (p2 == 0)
		return (0);
	p3 = niketa2(mod, p2, dict);
	if (p3 == 0)
		return (0);
	return (p3);
}
