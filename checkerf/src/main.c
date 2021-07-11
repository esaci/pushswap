/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:59:18 by esaci             #+#    #+#             */
/*   Updated: 2021/04/12 12:59:21 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

void	game_init(t_game *game, int i)
{
	while (i < 6)
		game->flag[i++] = 0;
	game->str = NULL;
	game->fd = 0;
	if (!checker(game->argc, game->argv2, game, 1))
		ft_stop4("1", game);
	if (game->fd < 0)
		ft_stop4("1", game);
	game->a.ptr = init_ptr(game->argc, game->argv2, game->count);
	game->size = game->argc - game->count - 1;
	game->a.len = game->size;
	game->b.ptr = malloc(sizeof(int) * game->a.len);
	if (!(game->b.ptr))
		ft_stop4("2", game);
}

int	doublon_int(t_stack *a)
{
	int		i;
	int		j;

	i = 0;
	while (i < (int)a->len)
	{
		j = i + 1;
		while (j < (int)a->len)
		{
			if (a->ptr[i] == a->ptr[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.argc = argc;
	if (argc >= 2)
	{
		game.argv2 = game_char(argc, argv, &game);
		game_init(&game, 0);
		if (!game.a.ptr || !doublon_int(&game.a))
			ft_stop4("3", &game);
		game.b.len = 0;
		ft_ch(&game, 0, createaction());
		free(game.a.ptr);
		free(game.b.ptr);
		if (game.flag[6])
			freechar(game.argv2);
	}
	return (0);
}
