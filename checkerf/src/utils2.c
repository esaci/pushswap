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

bool	checker_nbr(char *nbr)
{
	int		count1;
	int		signe;

	count1 = 0;
	signe = 1
	if (nbr[count1] == '-')
	{
		neg = -1;
		count1++;
	}
	while (nbr[count1])
	{
		if (nbr[count1] < 48 || nbr[count1] > 57 || count1 > 10 + neg)
			return (false);
		i++;
	}
	if ((nbr[count1] == 0 && i < 1 + neg) || check_int(nbr, i) == false)
		return (false);
	return (true);
}

int		checker(int argc, char **argv, t_game *game)
{
	int		count1;
	int		count2;

	count1 = 1;
	while (count1 < argc && argv[count1][0] == '-' && !checker_nbr(argv[count1]))
	{
		count2 = 1;
		while (argv[count1][count2])
		{
			if (argv[count1][count2] == 'c')
				pars->opt_c = true;
			else if (argv[count1][count2] == 'v')
				pars->opt_v = true;
			else if (argv[count1][count2] == 'f')
				pars->opt_f = true;
			else
				return (false);
			count2++;
		}
		if (pars->opt_f == true && !pars->file && count1 + 1 < argc)
			pars->file = argv[++count1];
		i++;
	}
	pars->nb_opt = count1 - 1;
	return (true);
}
