/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaccount1 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:17:12 by esaci             #+#    #+#             */
/*   Updated: 2021/04/12 14:17:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

int		c_int(char *nbr)
{
	if (ft_strncmp(ft_itoa(ft_atoi(nbr)), nbr, ft_strlen(nbr)))
		return(0);
	return (1);
}

int		c_nbr(char *nbr)
{
	int		count1;
	int		signe;

	count1 = 0;
	signe = 1
	if (nbr[count1] == '-')
	{
		signe = -1;
		count1++;
	}
	while (nbr[count1])
	{
		if (!ft_isdigit(nbr[count1]) || count1 > (10 - 1 * signe))
			return (0);
		i++;
	}
	if ((nbr[count1] == 0 && i < 1 - 1 * signe) || c_int(nbr) == 0)
		return (false);
	return (true);
}

int		checker(int argc, char **argv, t_game *game)
{
	int		count1;
	int		count2;

	count1 = 1;
	while (count1 < argc && argv[count1][0] == '-' && !c_nbr(argv[count1]))
	{
		count2 = 1;
		while (argv[count1][count2])
		{
			if (argv[count1][count2] == 'c')
				game->flag[0] = 1;
			else if (argv[count1][count2] == 'v')
				game->flag[1] = 1;
			else if (argv[count1][count2] == 'f')
				game->flag[2] = 1;
			else
				return (false);
			count2++;
		}
		if (!game->str && game->flag[2] == 1 && count1 + 1 < argc)
			game->str = argv[++count1];
		else
			count1++;
	}
	game->nb_opt = count1 - 1;
	return (true);
}
