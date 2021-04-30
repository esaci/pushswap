/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:09:36 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 12:09:43 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->len <= 1)
		return ;
	temp = stack->ptr[stack->len - 2];
	stack->ptr[stack->len - 2] = stack->ptr[stack->len - 1];
	stack->ptr[stack->len - 1] = temp;
}

void	push(t_stack *s, t_stack *d)
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

void	rotate(t_stack *s)
{
	int		temp;
	size_t	i;

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

void	reverserotate(t_stack *stack)
{
	int		temp;
	size_t	i;

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

void	ft_lecteur(char *inst, t_game *game)
{
	if (!ft_strncmp(inst, "sa", 3))
		return (swap(&game->a));
	else if (!ft_strncmp(inst, "sb", 3))
		return (swap(&game->b));
	else if (!ft_strncmp(inst, "pa", 3))
		return (push(&game->b, &game->a));
	else if (!ft_strncmp(inst, "ra", 3))
		return (rotate(&game->a));
	else if (!ft_strncmp(inst, "rb", 3))
		return (rotate(&game->b));
	else if (!ft_strncmp(inst, "rr", 3))
	{
		rotate(&game->a);
		return(rotate(&game->b));
	}
	else if (!ft_strncmp(inst, "pb", 3))
		return (push(&game->a, &game->b));
	else if (!ft_strncmp(inst, "rra", 3))
		return (reverserotate(&game->a));
	else if (!ft_strncmp(inst, "rrb", 3))
		return (reverserotate(&game->b));
	else if (!ft_strncmp(inst, "rrr", 3))
	{
		reverserotate(&game->a);
		reverserotate(&game->b);
	}
}
