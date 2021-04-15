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

int		*listeur(int *list, int len,char *line, char **action)
{
	int		*list2;
	int		i;
	int		y;

	if (!(list2 = malloc(sizeof(int) * (len + 2))))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
	i = 0;
	while (i < len)
	{
		list2[i] = list[i];
		i++;
	}
	y = 0;
	while (action[y])
	{
		if (!ft_strncmp(line, action[y], 3))
			break;
		y++;
	}
	/* printf("okk laction %s soit %d dans %d et len %d\n", action[y], y, i, len); */
	list2[i] = y;
	list2[++i] = 0;
	free(list);
	return (list2);
}

char	**createaction()
{
	int		i;
	char	**action;

	if (!(action = malloc(sizeof(char*) * 12)))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
	i = 0;
	while (i < 11)
	{
		if (!(action[i] = malloc(sizeof(char) * 4)))
		{
			write(1, "Erreur malloc\n", 14);
			exit(1);
		}
		i++;
	}
	action[0][0] = 's';
	action[0][1] = 'a';
	action[0][2] = 0;
	action[1][0] = 's';
	action[1][1] = 'b';
	action[1][2] = 0;
	action[2][0] = 's';
	action[2][1] = 's';
	action[2][2] = 0;
	action[3][0] = 'p';
	action[3][1] = 'a';
	action[3][2] = 0;
	action[4][0] = 'p';
	action[4][1] = 'b';
	action[4][2] = 0;
	action[5][0] = 'r';
	action[5][1] = 'a';
	action[5][2] = 0;
	action[6][0] = 'r';
	action[6][1] = 'b';
	action[6][2] = 0;
	action[7][0] = 'r';
	action[7][1] = 'r';
	action[7][2] = 0;
	action[8][0] = 'r';
	action[8][1] = 'r';
	action[8][2] = 'a';
	action[8][3] = 0;
	action[9][0] = 'r';
	action[9][1] = 'r';
	action[9][2] ='b';
	action[9][3] = 0;
	action[10][0] = 'r';
	action[10][1] = 'r';
	action[10][2] = 'r';
	action[10][3] = 0;
	return (action);
}

void	freeaction(char **action)
{
	int		i;

	i = 0;
	while (i < 11)
		free(action[i++]);
	free(action);
}

int		checkaction(char *line, char **action)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(line, action[i], 3))
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
		i++;
	}
}

void	ft_ch(t_game *game)
{
	char		*line;
	char		**action;
	int			*list;
	int			len;

	len = 0;
	action = createaction();
	if (!(list = malloc(sizeof(int) * 2)))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
	list[0] = 0;
	while (get_next_line(game->fd, &line))
	{
		if (!checkaction(line, action))
		{
			write(2, "Error mauvaise action\n", 22);
			free(line);
			return ;
		}
		list = listeur(list, len, line, action);
		len++;
		free(line);
	}
	free(line);
	applications(list, game, action, len);
	free(list);
	if (is_good(game) > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freeaction(action);
}
