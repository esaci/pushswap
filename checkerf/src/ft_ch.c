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

char	*rempliractio(char action[11][4])
{
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
}

int		checkaction(char *line)
{
	int		i;
	char	action[11][4];
	int		len;

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
	i = 0;
	while (i < 1)
	{
		if (!ft_strncmp(line, action[i], len))
			return (1);
		i++;
	}
	return (0);
}

void	ft_ch(t_game *game)
{
	char		*line;
	char		*list;
	int			len;

	len = 1;
	if (!(list = malloc(sizeof(char) * len * 4)))
	{
		write(1, "Erreur malloc\n", 14);
		exit(1);
	}
	while (get_next_line(game->fd, &line))
	{
		if (!checkaction(line))
		{
			write(2, "Error mauvaise action\n", 22);
			free(line);
			return ;
		}
		listeur(list, len);
		len++;
	}
	apply_moves(list, game);
	ft_lstclear(&list, &free);
	if (is_sort(&game->a) == true && game->b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
