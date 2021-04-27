/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:51:22 by esaci             #+#    #+#             */
/*   Updated: 2021/04/27 12:51:23 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

void	ft_clear(t_game *game, char *str)
{
	int		i;
	int		s;
	int		y;

	i = ft_strlen(game->str) - 1;
	s = ft_strlen(str);
	while (i > s)
	{
		if (ft_strncmp(str, (game->str + i - s), s))
		{
			y = 0;
			while(y < s)
			{
				game->str[i - y] = 0;
				y++;
			}
		}
		i--;
	}
}

void	optirr(t_game *game, char *str)
{
	if (game->rbc == 0 && str[1] == 'a')
		game->rbc = 1;
	else if (game->rbc >= 1 && str[1] == 'a')
	{
		ft_clear(game, "rb");
		str[1] = 'r';
		game->rbc--;
	}
	if (game->rac == 0 && str[1] == 'b')
		game->rac = 1;
	else if (game->rac >= 1 && str[1] == 'b')
	{
		ft_clear(game, "ra");
		str[1] = 'r';
		game->rac--;
	}
}

void	optirrr(t_game *game, char *str)
{
	if (game->rrbc == 0 && str[2] == 'a')
		game->rrbc = 1;
	else if (game->rrbc >= 1 && str[2] == 'a')
	{
		ft_clear(game, "rrb");
		str[2] = 'r';
		game->rrbc--;
	}
	if (game->rrac == 0 && str[2] == 'b')
		game->rrac = 1;
	else if (game->rrac >= 1 && str[2] == 'b')
	{
		ft_clear(game, "rra");
		str[2] = 'r';
		game->rrac--;
	}
}

int		gestrr(t_game *game, char *str)
{
	if (str[0] == 'r')
	{
		if (str[1] == 'r')
			optirrr(game, str);
		else
			optirr(game, str);
	}
	return(0);
}
