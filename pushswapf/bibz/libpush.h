/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:31:31 by esaci             #+#    #+#             */
/*   Updated: 2021/04/19 10:31:36 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECK_H
# define LIBCHECK_H

#include "../../fct/libft/libft.h"
#include "../../fct/GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_stack
{
	int			*ptr;
	size_t		len;
	int			max;
	int			min;
	int			prem;
	int			dern;
	int			flag;
}				t_stack;

typedef struct	s_game
{
	int			flag[4];
	int			count;
	int			fd;
	char		*list;
	char		*str;
	size_t		size;
	t_stack		a;
	t_stack		b;
}				t_game;

void			stack_init(t_stack *s);
int				*readlist(int argc, char **argv, int count);
int				checker(int argc, char **argv, t_game *game);
int				is_good(t_game *game);
void			ft_lecteur(char *inst, t_game *game);
void			updatelist(t_game *game, char *str);
void			tech_trois(t_game *game);
int				value_premier(t_stack *stack, int value, t_game *game);
void			tech_mquinze(t_game *game);
#endif
