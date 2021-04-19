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

void		stack_init(t_stack *s)
{
	size_t	i;

	i = 1;
	if (s->len == 0)
		return ;
	s->prem = s->ptr[s->len - 1];
	s->dern = s->ptr[0];
	s->min = s->dern;
	s->max = s->dern;
	while (i < s->len)
	{
		if (s->ptr[(int)i] > s->max)
			s->max = s->ptr[(int)i];
		if (s->ptr[(int)i] < s->min)
			s->min = s->ptr[(int)i];
		i++;
	}
}

void		updatelist(t_game *game, char *str)
{
	size_t		len;
	char		*str2;
	size_t		i;
	size_t		y;

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
	while (y < ft_strlen(str))
	{
		str2[i + y] = str[y];
		y++;
	}
	str2[i + y++] = '\n';
	str2[i + y] = '\0';
	free(game->str);
	game->str = str2;
	ft_lecteur(str, game);
}

void		tech_trois(t_game *game)
{
	if (game->a.ptr[2] < game->a.ptr[0])
	{
		if (game->a.ptr[2] < game->a.ptr[1])
		{
			updatelist(game, "ra");
			updatelist(game, "sa");
		}
		else
		{
			updatelist(game, "rra");
			updatelist(game, "rra");
		}
	}
	else if (game->a.ptr[1] < game->a.ptr[0])
		updatelist(game, "sa");
	else
	{
		updatelist(game, "rra");
		updatelist(game, "sa");
	}
}
