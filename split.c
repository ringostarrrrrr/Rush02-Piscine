/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:09:16 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 20:50:30 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	is_splitter(char c, char *c_set, char *c_set2)
{
	unsigned int	cnt;

	cnt = 0;
	while (c_set[cnt] != '\0' || c_set2[cnt] != '\0')
	{
		if (c == c_set[cnt] || c == c_set2[cnt])
			return (1);
		cnt ++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		dest[counter] = src[counter];
		counter ++;
	}
	dest[counter] = '\0';
	return (dest);
}

int	count_strs(char *str, char *c_set, char *c_set2)
{
	unsigned int	cnt_str;
	unsigned int	cnt;

	cnt = 0;
	cnt_str = 0;
	while (str[cnt] != '\0')
	{
		while (is_splitter(str[cnt], c_set, c_set2) == 1)
			cnt++;
		if (str[cnt] == '\0')
			break ;
		cnt_str++;
		while (is_splitter(str[cnt], c_set, c_set2) == 0 && str[cnt] != '\0')
			cnt++;
	}
	return (cnt_str);
}

char	**ft_split(char *str, char *c_set, char *c_set2)
{
	char			*answer;
	char			**ans_set;
	unsigned int	count;

	answer = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strcpy(answer, str);
	ans_set = malloc(sizeof(*ans_set) * (count_strs(str, c_set, c_set2) + 1));
	if (ans_set == NULL || answer == NULL)
		return (NULL);
	ans_set[count_strs(str, c_set, c_set2)] = NULL;
	count = 0;
	while (*answer != '\0')
	{
		while (is_splitter(*answer, c_set, c_set2) == 1)
			answer++;
		if (*answer == '\0')
			break ;
		ans_set[count++] = answer;
		while (is_splitter(*answer, c_set, c_set2) == 0 && *answer != '\0')
			answer++;
		if (*answer == '\0')
			break ;
		*(answer++) = '\0';
	}
	return (ans_set);
}
