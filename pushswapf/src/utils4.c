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
		imin += 1;
	else
		imin = game->b.len - imin - 1;
	if (imax < game->b.len / 2)
		imax += 1;
	else
		imax = game->b.len - imax - 1;
	if (imax < imin)
		return (game->b.max);
	return (game->b.min);
}

void	new_min(t_game *game)
{
	size_t	count;

	if ((game->a.prem > game->b.min && game->b.len > 0)
		|| is_goodsansb(game) == 1)
		return ;
	if (game->a.prem == game->a.min)
	{
		game->a.fsort = 1;
		updatelist(game, "ra");
		return (new_min(game));
	}
	count = check_value(&game->a, game->a.min) + 1;
	while (count < game->a.len - 1)
	{
		if (game->a.ptr[count] < game->a.prem)
			return ;
		count++;
	}
	game->a.fmax = game->a.prem;
	updatelist(game, "ra");
	return (new_min(game));
}

void	fullpushb(t_game *game)
{
	int		temp;

	while (game->b.len > 0)
	{
		temp = minormax(game);
		value_premierb(temp, game);
		updatelist(game, "pa");
		new_min(game);
	}
}

void	bborneur(t_game *game, int bornemin, int bornemax)
{
	if (!(bornemin < bornemax))
		return ;
	while (game->b.len >= 12 &&
		check_borne(&game->b, bornemin, game->b.max) == 1)
	{
		if ((game->b.prem >= bornemin &&
			game->b.prem <= game->b.max) || game->b.prem == game->b.min)
		{
			updatelist(game, "pa");
			new_min(game);
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
		if (game->a.prem >= bornemin && game->a.prem <= bornemax)
			updatelist(game, "pb");
		else
			updatelist(game, "ra");
	}
	if (game->a.fsort == 1)
	{
		while (game->a.dern != game->a.fmax)
			updatelist(game, "ra");
	}
	bborneur(game, is_median(&game->b), bornemax);
}
