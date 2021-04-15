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
}				t_stack;

typedef struct	s_game
{
	int			flag[4];
	int			count;
	int			fd;
	char		*str;
	size_t		size;
	t_stack		a;
	t_stack		b;
}				t_game;

void			ft_lecteur(char *inst, t_game *game);
int				checker(int argc, char **argv, t_game *game);
int				*readlist(int argc, char **argv, int count);
int				c_int(char *nbr);
void			ft_ch(t_game *game);
int				is_good(t_game *game);
#endif
