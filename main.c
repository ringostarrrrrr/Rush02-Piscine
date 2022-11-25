/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:53:39 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 23:08:38 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	main(int argc, char **argv)
{
	unsigned int	num;
	t_dict			*dictionary;

	if (argc == 2)
	{
		if (ft_argcheck(argc, argv) >= 0)
		{
			dictionary = contain("numbers.dict");
			num = (unsigned int)ft_argcheck(argc, argv);
			nketa(num, dictionary);
		}
	}
	else if (argc == 3)
	{
		if (ft_argcheck(argc, argv) >= 0)
		{
			dictionary = contain(argv[1]);
			num = (unsigned int)ft_argcheck(argc, argv);
			nketa(num, dictionary);
		}
	}
	free(dictionary);
	return (0);
}
