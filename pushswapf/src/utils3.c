/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:08:21 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 12:08:25 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../bibz/libpush.h"

int		is_good(t_game *game)
{
	size_t		i;

	i = 0;
	while (i < game->a.len - 1)
	{
		if (game->a.ptr[(int)i] < game->a.ptr[(int)i + 1])
			return (-1);
		i++;
	}
	if (game->b.len != 0)
		return (-2);
	return (1);
}

size_t	check_value(t_stack *stack, int value)
{
	size_t	i;

	i = 0;
	while (i < stack->len && stack->ptr[i] != value)
		i++;
	return (i);
}

int		value_premier(t_stack *stack, int value, t_game *game)
{
	size_t	ivalue;

	ivalue = check_value(stack, value);
	if (ivalue == stack->len)
		return (0);
	if (ivalue >= stack->len / 2)
	{
		while (stack->prem != value)
			updatelist(game, "ra");
	}
	else
	{
		while (stack->prem != value)
			updatelist(game, "rra");
	}
	return (1);
}

