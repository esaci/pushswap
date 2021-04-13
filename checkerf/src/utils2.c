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

int		checker(int argc, char **argv, t_game *game)
{
	int		count1;
	int		count2;

	count1 = 1;
	while (count1 < argc && argv[count1][0] == '-' && !c_int(argv[count1]))
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
				return (0);
			count2++;
		}
		if (!game->str && game->flag[2] == 1 && count1 + 1 < argc)
			game->str = argv[++count1];
		else
			count1++;
	}
	game->count = count1 - 1;
	return (1);
}

int		*readlist(int argc, char **argv, int count)
{
	int		*ptr;
	int		i;
	int		j;

	i = 1 + count;
	while (i < argc)
	{
		if (argv[i][0] == 0 || !c_int(argv[i]))
			return (0);
		i++;
	}
	if (argc - count < 2)
		return (0);
	if (!(ptr = malloc(sizeof(int) * argc - 1 - count)))
		return (0);
	j = 0;
	i--;
	while (i > count)
		ptr[j++] = ft_atoi(argv[i--]);
	return (ptr);
}
