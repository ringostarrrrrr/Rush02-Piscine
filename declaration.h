/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoyama <kaoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:15:07 by kaoyama           #+#    #+#             */
/*   Updated: 2022/05/08 20:44:55 by kaoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_dictionary{
	unsigned int	key;
	char			*value;
}	t_dict;

extern t_dict		*contain(char *filepath);
extern char			**ft_split(char *str, char *charset, char *charset2);
extern	int			ft_strlen(char *str);
extern	int			count_strs(char *str, char *charset, char *charset2);
extern	char			*ft_strcat_space(char *ans, char *value);
extern	char			*miketa(unsigned int n, char *ans, t_dict dict[]);
extern	char			*ft_delete_lastspace(char *ans);
extern	void			display(char *ans);
extern	void			ifzero(unsigned int n, char *ans, t_dict dict[]);
extern	unsigned int	ft_power(unsigned int nb, unsigned int power);
extern	void			nketa(unsigned int n, t_dict dict[]);
extern char			*cut_space_value(char *str);
extern int			cut_space_key(char *str);
extern void			ft_putstr(char *str);
extern unsigned int	ft_strlen_arg(unsigned int argc, char **argv);
extern long			ft_atoi_mini(int argc, char **argv);
extern long			ft_argcheck(int argc, char **argv);

#endif