#ifndef LIBCHECK_H
# define LIBCHECK_H

typedef struct	s_stack
{
	int			*ptr;
	size_t		len;
}				t_stack;

void        ft_lecteur(char *inst, t_stack *a, t_stack *b);
#endif