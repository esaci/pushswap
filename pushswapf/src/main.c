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

void	algo(t_game *game)
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

int	doublon_int(t_stack *a, t_game *game)
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
				ft_stop3("3", game);
			j++;
		}
		i++;
	}
	return (1);
}

void	game_init2(t_game *game, char **argv)
{
	game->a.ptr = readlist(game->argc, argv, game->count);
	game->size = game->argc - game->count - 1;
	game->a.len = game->size;
	game->a.flag = 0;
	game->b.flag = 1;
	game->b.ptr = malloc(sizeof(int) * game->a.len);
	if (!(game->b.ptr))
		ft_stop3("2", game);
}

void	game_init(char **argv, t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
		game->flag[i++] = 0;
	game->str = malloc(sizeof(char) * 1);
	if (!(game->str))
		ft_stop2("malloc");
	*game->str = '\0';
	game->fd = 1;
	if (!checker2(game->argc, argv, game, 1))
	{
		free(game->str);
		ft_stop3("1", game);
	}
	game_init2(game, argv);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**argv2;

	game.rac = 0;
	game.rrac = 0;
	game.rbc = 0;
	game.rrbc = 0;
	game.argc = argc;
	if (game.argc >= 2)
	{
		argv2 = game_char(argc, argv, &game);
		game_init(argv2, &game);
		if (!game.a.ptr || !doublon_int(&game.a, &game))
			ft_stop3("full", &game);
		game.b.len = 0;
		if (is_good2(&game) < 1)
			algo(&game);
		free(game.a.ptr);
		free(game.b.ptr);
		game.rrbc = ft_clear2(&game);
		write(game.fd, game.str, game.rrbc);
		free(game.str);
	}
	return (0);
}
