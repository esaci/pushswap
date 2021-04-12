#include "../bibz/libcheck.h"

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
	if (!ft_strncmp(inst, "sa", 2))
		return (swap(a));
	else if (!ft_strncmp(inst, "sb", 2))
		return (swap(b));
	else if (!ft_strncmp(inst, "pa", 2))
		return (push(b, a));
	else if (!ft_strncmp(inst, "ra", 2))
		return (rotate(a));
	else if (!ft_strncmp(inst, "rb", 2))
		return (rotate(b));
	else if (!ft_strncmp(inst, "pb", 2))
		return (push(a, b));
	else if (!ft_strncmp(inst, "rra", 3))
		return (reverserotate(a));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (reverserotate(b));
	else if (!ft_strncmp(inst, "rrr", 3))
	{
		reverserotate(a);
		reverserotate(b);
	}
	else if (!ft_strncmp(inst, "rr", 2))
	{
		rotate(a);
		return (rotate(b));
	}
}
