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

void swap(t_stack *stack)
{
	int temp;

	if (stack->len <= 1)
		return ;
	temp = stack->ptr[stack->len - 2];
	stack->ptr[stack->len - 2] = stack->ptr[stack->len - 1];
	stack->ptr[stack->len - 1] = temp;
	stack->prem = temp;
	stack_update(stack, 0);
}

void push(t_stack *d, t_stack *s)
{
	int			*nptr;
	size_t		i;

	if (s->len <= 0)
		return ;
	if (d->flag == 1)
	{
		if (!(nptr = malloc(sizeof(int) * (d->len + 1))))
		{
			write(1, "Malloc probleme \n", 17);
			exit(1);
		}
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
	stack_update(s, 0);
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
	stack_update(stack, 0);
}

void ft_lecteur(char *inst, t_game *game)
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
		reverserotate(&game->b);
	}
	else if (!ft_strncmp(inst, "rr", 2))
	{
		rotate(&game->a);
		return (rotate(&game->b));
	}
}
