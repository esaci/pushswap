/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:08:21 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 12:08:25 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

int	is_good(t_game *game)
{
	size_t		i;

	i = 0;
	while (i < game->a.len - 1)
	{
		if (game->a.ptr[(int)i] < game->a.ptr[(int)i + 1])
		{
			return (-1);
		}
		i++;
	}
	if (game->b.len != 0)
		return (-2);
	return (1);
}

int	*listeur(int *list, int len, char *line, char **action)
{
	int		*list2;
	int		y;
	int		i;

	list2 = malloc(sizeof(int) * (len + 2));
	if (!(list))
		ft_stop5();
	i = 0;
	while (i < len)
	{
		list2[i] = list[i];
		i++;
	}
	y = 0;
	while (action[y])
	{
		if (!ft_strncmp(line, action[y], ft_strlen(line)))
			break ;
		y++;
	}
	list2[i] = y;
	list2[++i] = 0;
	free(list);
	return (list2);
}

void	ft_stop5(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_stop4(char *str, t_game *game)
{
	if (game->flag[6])
		freechar(game->argv2);
	free(game->str);
	if (str[0] == '1')
		ft_stop5();
	free(game->a.ptr);
	if (str[0] == '2')
		ft_stop5();
	free(game->b.ptr);
	ft_stop5();
}
