#include "libcheck.h"

void swap(t_stack *stack)
{
	int temp;

	if (stack->len <= 1)
		return ;
	temp = stack->ptr[stack->len - 2];
	stack->ptr[stack->len - 2] = stack->ptr[stack->len - 1];
	stack->ptr[stack->len - 1] = temp;
}

void push(t_stack *s, t_stack *d)
{
	if (s->len <= 0)
		return ;
	if (s->len > 0)
	{
		d->ptr[d->len] = s->ptr[s->len - 1];
		d->len += 1;
		s->len -= 1;
	}
}

void rotate(t_stack *s)
{
	int temp;
	size_t i;

	if (s->len <= 1)
		return ;
	i = s->len - 1;
	temp = s->ptr[i];
	while (i > 0)
	{
		s->ptr[i] = s->ptr[i - 1];
		i--;
	}
	s->ptr[i] = temp;
}

void reverserotate(t_stack *stack)
{
	int 	temp;
	size_t 	i;

	if (stack->len <= 1)
		return ;
	temp = stack->ptr[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->ptr[i] = stack->ptr[i + 1];
		i++;
	}
	stack->ptr[i] = temp;
}

void ft_lecteur(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(inst, "sa"))
		return (swap(a));
	else if (!ft_strcmp(inst, "sb"))
		return (swap(b));
	else if (!ft_strcmp(inst, "pa"))
		return (push(b, a));
	else if (!ft_strcmp(inst, "ra"))
		return (rotate(a));
	else if (!ft_strcmp(inst, "rb"))
		return (rotate(b));
	else if (!ft_strcmp(inst, "pb"))
		return (push(a, b));
	else if (!ft_strcmp(inst, "rr"))
	{
		rotate(a);
		return (rotate(b));
	}
	else if (!ft_strcmp(inst, "rra"))
		return (reverserotate(a));
	else if (!ft_strcmp(inst, "rrb"))
		return (reverserotate(b));
	else if (!ft_strcmp(inst, "rrr"))
	{
		reverserotate(a);
		reverserotate(b);
	}
}
