/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:52:13 by esaci             #+#    #+#             */
/*   Updated: 2021/04/13 13:52:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

int		*listeur(int *list, int len,char *line, char **action)
{
	int		*list2;
	int		i;
	int		y;

	if (!(list2 = malloc(sizeof(int) * (len))))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
	i = 0;
	while (list[i])
	{
		list2[i] = list[i];
		i++;
	}
	y = 0;
	while (action[y])
	{
		len = (ft_strlen(action[i]) > ft_strlen(line)) ? ft_strlen(action[i]) : ft_strlen(line);
		if (ft_strncmp(line, action[y], len + 1))
			break;
		y++;
	}
	list2[++i] = y;
	list2[++i] = 0;
	if (len == 0)
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
	action[0] = "sa";
	action[1] = "sb";
	action[2] = "ss";
	action[3] = "pa";
	action[4] = "pb";
	action[5] = "ra";
	action[6] = "rb";
	action[7] = "rr";
	action[8] = "rra";
	action[9] = "rrb";
	action[10] = "rrr";
	return (action);
}

int		checkaction(char *line, char **action)
{
	int		i;
	int		len;

	i = 0;
	while (i < 1)
	{
		len = (ft_strlen(action[i]) > ft_strlen(line)) ? ft_strlen(action[i]) : ft_strlen(line);
		if (!ft_strncmp(line, action[i], len + 1))
			return (1);
		i++;
	}
	return (0);
}

/* void	applications(char *list, t_game *game)
{
	while (list)
	{
		ft_lecteur(&game->a, &game->b, list);
		i++;
	}
} */

void	ft_ch(t_game *game)
{
	char		*line;
	char		**action;
	int			*list;
	int			len;
	int			i;

	len = 0;
	action = createaction();
	if (!(list = malloc(sizeof(char) * len * 4)))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
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
	}
/* 	applications(list, game); */
	i = 0;
	while (list[i])
		printf("%d", list[i++]);
/* 	ft_lstclear(&list, &free);
	if (is_sort(&game->a) == true && game->b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3); */
}
