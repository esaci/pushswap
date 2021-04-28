/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:04:58 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 16:05:00 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

void		stack_update(t_stack *s, int i)
{
	size_t	count;

	count = 1;
	s->len = s->len + i;
	if (s->len == 0)
		return ;
	s->prem = s->ptr[s->len - 1];
	s->dern = s->ptr[0];
	s->min = s->dern;
	s->max = s->dern;
	while (count < s->len)
	{
		if (s->ptr[(int)count] > s->max)
			s->max = s->ptr[(int)count];
		if (s->ptr[(int)count] < s->min)
			s->min = s->ptr[(int)count];
		count++;
	}
}

void		updatelist(t_game *game, char *str)
{
	size_t		len;
	char		*str2;
	size_t		i;
	size_t		y;

	ft_lecteur(str, game);
	len = ft_strlen(game->str);
	if (!(str2 = malloc(sizeof(char) * (len + ft_strlen(str) + 3))))
		exit(1);
	i = 0;
	while (i < len)
	{
		str2[i] = game->str[i];
		i++;
	}
	y = 0;
	str = gestrr(game, str, str2);
	while (y < ft_strlen(str))
	{
		str2[i + y] = str[y];
		y++;
	}
	str2[i + y++] = '\n';
	str2[i + y] = '\0';
	free(game->str);
	game->str = str2;
}

void		tech_trois(t_game *game)
{
	if (game->a.ptr[2] > game->a.ptr[0])
	{
		if (game->a.ptr[2] > game->a.ptr[1])
		{
			updatelist(game, "ra");
			if ((game->a.ptr[2] > game->a.ptr[1]))
				updatelist(game, "sa");
		}
		else
		{
			updatelist(game, "rra");
		}
	}
	else if (game->a.ptr[1] < game->a.ptr[2])
		updatelist(game, "sa");
	else
	{
		updatelist(game, "rra");
		updatelist(game, "sa");
	}
}

void	tech_mquinze(t_game *game)
{
	while (game->a.len > 3)
	{
		value_premiera(game->a.min, game);
		updatelist(game, "pb");
	}
	if (is_goodsansb(game) < 1)
		tech_trois(game);
	while (game->b.len > 0)
		updatelist(game, "pa");
}

void	tech_pquinze(t_game *game)
{
	int		bornemax;
	int		bornemin;

	bornemin = game->a.min;
	game->a.fsort = 0;
	while (is_good(game) < 1)
	{
		bornemax = is_median(&game->a);
		if (bornemax <= bornemin)
		{
			if (game->a.ptr[game->a.len - 1] > game->a.ptr[game->a.len - 2])
				updatelist(game, "sa");
			updatelist(game, "ra");
			updatelist(game, "ra");
			return ;
		}
		aborneur(game, bornemin, bornemax);
		bornemin = game->a.fmax + 1;
	}
}
