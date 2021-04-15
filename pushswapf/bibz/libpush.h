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
	char		*str;
	size_t		size;
	t_stack		a;
	t_stack		b;
}				t_game;

void		stack_init(t_stack *s);


#endif