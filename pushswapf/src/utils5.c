/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:05:54 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 18:05:56 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

int	check_borne(t_stack *s, int min, int max)
{
	size_t	count;

	count = 0;
	while (count < s->len)
	{
		if (s->ptr[count] >= min && s->ptr[count] <= max)
			return (1);
		count++;
	}
	return (0);
}

void	finupd(char *str2, int i, int y, t_game *game)
{
	str2[i + y++] = '\n';
	str2[i + y] = '\0';
	free(game->str);
	game->str = str2;
}

void	ft_stop2(char *str)
{
	if (str[0] == 'e')
		return ;
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_stop3(char *str, t_game *game)
{
	if (game->flag[4])
		freechar(game->argv2);
	free(game->str);
	if (str[0] == '1')
		ft_stop2("malloc");
	free(game->a.ptr);
	if (str[0] == '2')
		ft_stop2("malloc");
	free(game->b.ptr);
	ft_stop2("malloc");
}
