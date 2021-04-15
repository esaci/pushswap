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

int		is_good(t_game *game)
{
	size_t		i;

	i = 0;
	while (i < game->a.len - 1)
	{
		if (game->a.ptr[(int)i] < game->a.ptr[(int)i + 1])
			return (-1);
		i++;
	}
	if (game->b.len != 0)
		return (-2);
	return (1);
}
