/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:55:43 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 14:55:45 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

void		algo(t_game *game)
{
	stack_init(&game->a);
	if (game->a.len == 2)
		updatelist(game, "sa");
	else if (game->a.len == 3)
		tech_trois(game);
	else if (game->a.len <= 15)
		tech_mquinze(game);
	else
		tech_pquinze(game);
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


void		game_init2(t_game *game, int argc, char **argv)
{
	game->a.ptr = readlist(argc, argv, game->count);
	game->size = argc - game->count - 1;
	game->a.len = game->size;
	game->a.flag = 0;
	game->b.flag = 1;
	if (!(game->b.ptr = malloc(sizeof(int) * game->a.len)))
	{
		write(2, "Error\n", 6);
		free(game->a.ptr);
		exit(1);
	}
}

void		game_init(int argc, char **argv, t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
		game->flag[i++] = 0;
	if (!(game->str = malloc(sizeof(char) * 1)))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	*game->str = '\0';
	game->fd = 1;
	if (!checker(argc, argv, game, 1))
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
	game_init2(game, argc, argv);
}

int			main(int argc, char **argv)
{
	t_game game;

	game.rac = 0;
	game.rrac = 0;
	game.rbc = 0;
	game.rrbc = 0;
	if (argc >= 2)
	{
		game_init(argc, argv, &game);
		if (!game.a.ptr || !doublon_int(&game.a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		game.b.len = 0;
		if (is_good(&game) <= 0)
			algo(&game);
		if (game.fd > 1)
			close(game.fd);
		free(game.a.ptr);
		free(game.b.ptr);
		write(game.fd, game.str, ft_strlen(game.str));
		free(game.str);
	}
	return (0);
}
