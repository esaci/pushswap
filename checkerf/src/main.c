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

void		game_init(int argc, char **argv, t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
		game->flag[i++] = 0;
	game->str = NULL;
	game->fd = 0;
	if (!checker(argc, argv, game))
	{
		write(2, "Mauvaises Options\n", 14);
		exit(1);
	}
	if (game->flag[2] == 1)
		game->fd = open(game->str, O_RDONLY);
	if (game->fd < 0)
	{
		write(2, "Fichier non lu\n", 15);
		exit(1);
	}
	game->a.ptr = readlist(argc, argv, game->count);
	game->size = argc - game->count - 1;
	game->a.len = game->size;
	if (!(game->b.ptr = malloc(sizeof(int) * game->a.len)))
	{
		write(2, "Error\n", 6);
		free(game->a.ptr);
		exit(1);
	}
}

int			doublon_int(t_stack *a)
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
				free(a->ptr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
    t_game game;

    if (argc >= 2)
	{
        game_init(argc, argv, &game);
		if (!game.a.ptr || !doublon_int(&game.a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		game.b.len = 0;
		ft_ch(&game);
		if (game.fd > 0)
			close(game.fd);
		free(game.a.ptr);
		free(game.b.ptr);
	}
	return (0);
}
