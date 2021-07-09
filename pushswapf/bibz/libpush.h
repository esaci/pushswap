/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:31:31 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 16:16:41 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H

# include "../../fct/libft/libft.h"
# include "../../fct/GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int			*ptr;
	size_t		len;
	int			max;
	int			min;
	int			prem;
	int			dern;
	int			flag;
	int			fsort;
	int			fmax;
}				t_stack;

typedef struct s_game
{
	int			flag[4];
	int			count;
	int			fd;
	char		*list;
	char		*str;
	size_t		size;
	t_stack		a;
	t_stack		b;
	int			rac;
	int			rbc;
	int			rrac;
	int			rrbc;
	int			argc;
}				t_game;

void			stack_init(t_stack *s);
void			stack_update(t_stack *s, int i);
int				*readlist(int argc, char **argv, int count);
int				checker2(int argc, char **argv, t_game *game, int count1);
int				is_good2(t_game *game);
int				ft_lecteur(char *inst, t_game *game);
void			updatelist(t_game *game, char *str);
void			tech_trois(t_game *game);
int				value_premiera(int value, t_game *game);
int				value_premierb(int value, t_game *game);
void			tech_mquinze(t_game *game);
int				is_goodsansb(t_game *game);
int				is_median(t_stack *stack);
size_t			check_value(t_stack *stack, int value);
int				check_borne(t_stack *s, int min, int max);
void			aborneur(t_game *game, int bornemin, int bornemax);
void			tech_pquinze(t_game *game);
char			*gestrr(t_game *game, char *str, char *str2);
int				ft_clear2(t_game *game);
void			finupd(char *str2, int i, int y, t_game *game);
void			ft_stop2(char *str);
void			ft_stop3(char *str, t_game *game);
char			**game_char(int argc, char **argv, t_game *game);
void 			freechar(char **argv2);
#endif
