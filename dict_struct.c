/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:24:13 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 22:56:45 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*read_file(char *filepath)
{
	int		fd;
	char	*buffer;
	int		i;

	fd = open (filepath, O_RDWR);
	i = 2147483647;
	if (fd != -1)
	{
		buffer = (char *)malloc(sizeof(char) * i);
		read(fd, buffer, i);
		close (fd);
		return (buffer);
	}
	else
	{
		return (NULL);
	}
	return (0);
}

t_dict	*contain(char *filepath)
{
	char			*doc;
	int				i;
	int				j;
	char			**answer;
	t_dict			*dictlist;

	doc = read_file(filepath);
	answer = ft_split(doc, "\n", ":");
	i = 0;
	j = 0;
	dictlist = (t_dict *)malloc(sizeof(t_dict) * count_strs(doc, "\n", ":") + 1);
	while (answer[j] != 0)
	{
		dictlist[i].key = cut_space_key(answer[j]);
		dictlist[i].value = cut_space_value(answer[j + 1]);
		j += 2;
		i++;
	}
	return (dictlist);
}
