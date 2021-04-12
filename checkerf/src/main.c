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

#include "libcheck.h"

void		game_init(int argc, char **argv, t_game *game)
{
	int		i;

	i = 0;
	while (i < 4)
		game->flag[i++] = 0;
	game->str = NULL;
	game->fd = -1;
	if (!check_args(argc, argv, &pars))
	{
		write(2, "Wrong options\n", 14);
		exit(1);
	}
	if (game->opt_f == true)
		game->fd = open(game->file, O_RDONLY);
	if (game->fd < 0)
	{
		write(2, "Wrong file\n", 11);
		exit(1);
	}
	game->a.list = get_list(argc, argv, game->nb_opt);
	game->size = argc - 1 - game->nb_opt;
	game->a.size = game->size;
	return (pars);
}

int			main(int argc, char *argv)
{
    t_game game;

    if (argc >= 2)
	{
        game_init(argc, argv, &game);

}
