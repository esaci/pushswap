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

int	is_goodsansb(t_game *game)
{
	int		i;

	i = 0;
	while (i < (int)game->a.len - 1)
	{
		if (game->a.ptr[i] < game->a.ptr[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int	is_good2(t_game *game)
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

int	value_premiera(int value, t_game *game)
{
	size_t	ivalue;

	ivalue = check_value(&game->a, value);
	if (ivalue == game->a.len)
		return (0);
	if (ivalue >= game->a.len / 2)
	{
		while (game->a.prem != value)
			updatelist(game, "ra");
	}
	else
	{
		while (game->a.prem != value)
			updatelist(game, "rra");
	}
	return (1);
}

int	value_premierb(int value, t_game *game)
{
	size_t	ivalue;

	ivalue = check_value(&game->b, value);
	if (ivalue == game->b.len)
		return (0);
	if (ivalue >= game->b.len / 2)
	{
		while (game->b.prem != value)
			updatelist(game, "rb");
	}
	else
	{
		while (game->b.prem != value)
			updatelist(game, "rrb");
	}
	return (1);
}
