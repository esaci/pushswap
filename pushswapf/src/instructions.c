/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:49:02 by esaci             #+#    #+#             */
/*   Updated: 2021/04/19 11:49:07 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

int	swap(t_stack *stack)
{
	int	temp;

	if (stack->len <= 1)
		return (0);
	temp = stack->ptr[stack->len - 2];
	stack->ptr[stack->len - 2] = stack->ptr[stack->len - 1];
	stack->ptr[stack->len - 1] = temp;
	stack->prem = temp;
	stack_update(stack, 0);
	return (0);
}

int	push(t_stack *d, t_stack *s)
{
	int			*nptr;
	size_t		i;

	if (s->len <= 0)
		return (0);
	if (d->flag == 1)
	{
		nptr = malloc(sizeof(int) * (d->len + 1));
		if (!(nptr))
			ft_stop2("malloc");
		i = 0;
		while (i < d->len)
		{
			nptr[i] = d->ptr[i];
			i++;
		}
		free(d->ptr);
		d->ptr = nptr;
	}
	d->ptr[d->len] = s->ptr[s->len - 1];
	stack_update(s, -1);
	stack_update(d, 1);
	return (0);
}

int	rotate(t_stack *s)
{
	int			temp;
	size_t		i;

	if (s->len <= 1)
		return (0);
	i = s->len - 1;
	temp = s->ptr[i];
	while (i > 0)
	{
		s->ptr[i] = s->ptr[i - 1];
		i--;
	}
	s->ptr[0] = temp;
	stack_update(s, 0);
	return (0);
}

int	reverserotate(t_stack *stack)
{
	int			temp;
	size_t		i;

	if (stack->len <= 1)
		return (0);
	temp = stack->ptr[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->ptr[i] = stack->ptr[i + 1];
		i++;
	}
	stack->ptr[i] = temp;
	stack_update(stack, 0);
	return (0);
}

int	ft_lecteur(char *inst, t_game *game)
{
	if (!ft_strncmp(inst, "sa", 2))
		return (swap(&game->a));
	else if (!ft_strncmp(inst, "sb", 2))
		return (swap(&game->b));
	else if (!ft_strncmp(inst, "pa", 2))
		return (push(&game->a, &game->b));
	else if (!ft_strncmp(inst, "ra", 2))
		return (rotate(&game->a));
	else if (!ft_strncmp(inst, "rb", 2))
		return (rotate(&game->b));
	else if (!ft_strncmp(inst, "pb", 2))
		return (push(&game->b, &game->a));
	else if (!ft_strncmp(inst, "rra", 3))
		return (reverserotate(&game->a));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (reverserotate(&game->b));
	else if (!ft_strncmp(inst, "rrr", 3))
	{
		reverserotate(&game->a);
		return (reverserotate(&game->b));
	}
	rotate(&game->a);
	return (rotate(&game->b));
}
