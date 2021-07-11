/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcheck.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:49:29 by esaci             #+#    #+#             */
/*   Updated: 2021/04/26 11:49:38 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCHECK_H
# define LIBCHECK_H
# include "../../fct/libft/libft.h"
# include "../../fct/GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BLEU "\e[1;34m[0m"
# define CLEAN "\e[H\e[2J"
# define RESET "\033[0m"
# define NB_MOVES 11
# define DELAY 100000

typedef struct s_stack
{
	int			*ptr;
	size_t		len;
}				t_stack;

typedef struct s_game
{
	int			flag[7];
	int			count;
	int			fd;
	char		*str;
	size_t		size;
	t_stack		a;
	t_stack		b;
	int			argc;
	char		**argv2;
}				t_game;

void			ft_lecteur(char *inst, t_game *game);
int				checker(int argc, char **argv, t_game *game, int count2);
int				*init_ptr(int argc, char **argv, int count);
int				c_int(char *nbr);
void			ft_ch(t_game *game, int len, char **action);
int				is_good(t_game *game);
int				*listeur(int *list, int len, char *line, char **action);
char			**createaction(void);
void			optionv(t_game *game, char **action, int *list, int count);
void			ft_stop5(void);
void			ft_stop4(char *str, t_game *game);
char			**game_char(int argc, char **argv, t_game *game);
void			freechar(char **argv2);
#endif
