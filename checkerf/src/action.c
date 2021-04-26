/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:10:57 by esaci             #+#    #+#             */
/*   Updated: 2021/04/26 13:11:32 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

char	**createaction3(char **action)
{
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
	action[9][2] = 'b';
	action[9][3] = 0;
	action[10][0] = 'r';
	action[10][1] = 'r';
	action[10][2] = 'r';
	action[10][3] = 0;
	return (action);
}

char	**createaction2(char **action)
{
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
	action = createaction3(action);
	return (action);
}

char	**createaction(void)
{
	int		i;
	char	**action;

	if (!(action = malloc(sizeof(char*) * 12)))
	{
		write(2, "Erreur malloc\n", 14);
		exit(1);
	}
	i = 0;
	while (i < 11)
	{
		if (!(action[i] = malloc(sizeof(char) * 4)))
		{
			write(2, "Erreur malloc\n", 14);
			exit(1);
		}
		i++;
	}
	action = createaction2(action);
	return (action);
}
