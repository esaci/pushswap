#ifndef LIBCHECK_H
# define LIBCHECK_H

#include "../../fct/libft/libft.h"

typedef struct	s_stack
{
	int			*ptr;
	size_t		len;
}				t_stack;

typedef struct	s_game
{
	int			flag[4];
	int			fd;
	char		*str;
	size_t		size;
	size_t		nb_opt;
	t_stack		a;
	t_stack		b;
}				t_game;

void			ft_lecteur(char *inst, t_stack *a, t_stack *b);
int				checker(int argc, char **argv, t_game *game);
#endif
