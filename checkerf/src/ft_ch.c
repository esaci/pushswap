/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <esaci@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:52:13 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 14:03:43 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

void	freeaction(char **action, char *line, int *list)
{
	int		i;

	i = 0;
	while (i < 11)
		free(action[i++]);
	free(action);
	free(list);
	free(line);
}

int		checkaction(char *line, char **action)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(line, action[i], ft_strlen(line)))
			return (1);
		i++;
	}
	return (0);
}

void	applications(int *list, t_game *game, char **action, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_lecteur(action[list[i]], game);
		optionv(game, action, list, i);
		i++;
	}
	if (is_good(game) > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_ch(t_game *game, int len, char **action)
{
	char		*line;
	int			*list;
	int			i;

	if (!(list = malloc(sizeof(int) * 2)))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (get_next_line(game->fd, &line))
	{
		if (!checkaction(line, action))
		{
			write(2, "Error\n", 6);
			free(line);
			return ;
		}
		i++;
		list = listeur(list, len, line, action);
		len++;
		free(line);
	}
	applications(list, game, action, len);
	freeaction(action, line, list);
}
