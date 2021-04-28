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

void	ft_clear(char *str, char *str2)
{
	int		i;
	int		s;
	int		y;

	i = ft_strlen(str2) - 1;
	s = ft_strlen(str);
	while (i > s)
	{
		if (ft_strncmp(str, (str2 + i - s), s) == 0)
		{
			y = 0;
			while(y < s)
			{
				str2[i - s + y] = 'e';
				y++;
			}
			return ;
		}
		i--;
	}
}

int		ft_clear2(t_game *game)
{
	size_t		i;
	size_t		y;
	char		*str;

	i = ft_strlen(game->str) - 1;
	if (!(str = malloc(sizeof(char)* (i + 1))))
		exit(1);
	i = 0;
	y = 0;
	while (i < (ft_strlen(game->str)))
	{
		if (game->str[i] == 'e')
		{
			while(game->str[i] == 'e' || game->str[i] == '\n')
				i++;
		}
		str[y] = game->str[i];
		y++;
		i++;
	}
	str[y] = 0;
	free(game->str);
	game->str = str;
	return (y);
}

char	*optirr(t_game *game, char *str, char *str2)
{
	if (game->rbc == 0 && str[1] == 'a')
		game->rac += 1;
	else if (game->rbc >= 1 && str[1] == 'a')
	{
		ft_clear("rb", str2);
		game->rbc--;
		return("rr");
	}
	if (game->rac == 0 && str[1] == 'b')
		game->rbc += 1;
	else if (game->rac >= 1 && str[1] == 'b')
	{
		ft_clear("ra", str2);
		game->rac--;
		return("rr");
	}
	return(str);
}

char	*optirrr(t_game *game, char *str, char *str2)
{
	if (game->rrbc == 0 && str[2] == 'a')
		game->rrac += 1;
	else if (game->rrbc >= 1 && str[2] == 'a')
	{
		ft_clear("rrb", str2);
		game->rrbc--;
		return("rrr");
	}
	if (game->rrac == 0 && str[2] == 'b')
		game->rrbc += 1;
	else if (game->rrac >= 1 && str[2] == 'b')
	{
		ft_clear("rra", str2);
		game->rrac--;
		return("rrr");
	}
	return(str);
}

char	*gestrr(t_game *game, char *str, char *str2)
{
	if (str[0] == 'r')
	{
		if (str[1] == 'r')
			return(optirrr(game, str, str2));
		else
			return(optirr(game, str, str2));
	}
	game->rac = 0;
	game->rrac = 0;
	game->rbc = 0;
	game->rrbc = 0;
	return(str);
}
