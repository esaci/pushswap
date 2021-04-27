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

int		ft_clear(t_game *game)
{
	int		i;
	int		s;

	if (game->temp[0] == '\0')
		return (0);
	i = ft_strlen(game->str);
	s = ft_strlen(game->temp);
	while (i > s)
	{
		if (ft_strncmp(game->temp, (game->str + i - s), s) == s)
		{
			game->temp[0] = '\0';
			game->temp[1] = '\0';
			return (i + s);
		}
		i--;
	}
	return (0);
}

char	*optirr(t_game *game, char *str)
{
	if (game->rbc == 0 && str[1] == 'a')
		game->rac += 1;
	else if (game->rbc >= 1 && str[1] == 'a')
	{
		game->rbc--;
		game->temp[0] = 'b';
		return("rr");
	}
	if (game->rac == 0 && str[1] == 'b')
		game->rbc += 1;
	else if (game->rac >= 1 && str[1] == 'b')
	{
		game->rac--;
		game->temp[0] = 'a';
		return("rr");
	}
	return (str);
}

char	*optirrr(t_game *game, char *str)
{
	if (game->rrbc == 0 && str[2] == 'a')
		game->rrac += 1;
	else if (game->rrbc >= 1 && str[2] == 'a')
	{
		game->rrbc--;
		game->temp[0] = 'r';
		game->temp[1] = 'b';
		return("rrr");
	}
	if (game->rrac == 0 && str[2] == 'b')
		game->rrbc += 1;
	else if (game->rrac >= 1 && str[2] == 'b')
	{
		game->rrac--;
		game->temp[0] = 'r';
		game->temp[1] = 'a';
		return("rrr");
	}
	return(str);
}

char	*gestrr(t_game *game, char *str)
{
	game->temp[0] = '\0';
	game->temp[1] = '\0';
	if (str[0] == 'r')
	{
		if (str[1] == 'r')
			return(optirrr(game, str));
		return(optirr(game, str));
	}
	game->rac = 0;
	game->rrac = 0;
	game->rbc = 0;
	game->rrbc = 0;
	return(str);
}
