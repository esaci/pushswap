/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:35:05 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 16:35:06 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

int		minormax(t_game *game)
{
	size_t	imin;
	size_t	imax;

	imin = check_value(&game->b, game->b.min);
	imax = check_value(&game->b, game->b.max);
	if (imin < game->b.len / 2)
		imin++;
	else
		imin = game->b.len - imin - 1;
	if (imax < game->b.len / 2)
		imax++;
	else
		imax = game->b.len - imax - 1;
	if (imax < imin)
		return (game->b.max);
	return (game->b.min);
}

void	new_min(t_game *g, size_t count)
{
	if (g->a.prem <= g->a.min && !g->a.fsort && g->a.len + g->b.len <= 16)
	{
		g->a.fsort = 1;
		updatelist(g, "ra");
		return (new_min(g, 0));
	}
	if ((is_goodsansb(g) == 1) ||
		(g->a.prem > g->b.min && g->b.len > 0))
		return ;
	if (g->a.prem <= g->a.min)
	{
		g->a.fsort = 1;
		updatelist(g, "ra");
		return (new_min(g, 0));
	}
	count = check_value(&g->a, g->a.min) + 1;
	while (count < g->a.len - 1)
	{
		if (g->a.ptr[count] < g->a.prem)
			return ;
		count++;
	}
	g->a.fmax = g->a.prem;
	updatelist(g, "ra");
	return (new_min(g, 0));
}

void	fullpushb(t_game *game)
{
	int		temp;

	while (game->b.len > 0)
	{
		temp = minormax(game);
		value_premierb(temp, game);
		updatelist(game, "pa");
		new_min(game, 0);
	}
}

void	bborneur(t_game *game, int bornemin, int bornemax)
{
	if (!(bornemin < bornemax))
		return ;
	while (game->b.len >= 14 &&
		check_borne(&game->b, bornemin, game->b.max) >= 1)
	{
		if ((game->b.prem >= bornemin &&
			game->b.prem <= game->a.max) || game->b.prem == game->b.min)
		{
			updatelist(game, "pa");
			new_min(game, 0);
		}
		else
			updatelist(game, "rb");
	}
	fullpushb(game);
	aborneur(game, game->a.fmax + 1, bornemax);
}

void	aborneur(t_game *game, int bornemin, int bornemax)
{
	if (!(bornemin < bornemax))
		return ;
	while (check_borne(&game->a, bornemin, bornemax) == 1)
	{
		stack_update(&game->a, 0);
		if (game->a.prem >= bornemin && game->a.prem <= bornemax)
			updatelist(game, "pb");
		else
			updatelist(game, "ra");
	}
	if (game->a.fsort == 1)
	{
		while (game->a.dern != game->a.fmax)
			updatelist(game, "rra");
	}
	bborneur(game, is_median(&game->b), bornemax);
}
