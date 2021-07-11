/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:17:12 by esaci             #+#    #+#             */
/*   Updated: 2021/04/12 14:17:15 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libcheck.h"

int	c_int(char *nbr)
{
	char	*temp;
	int		fix;

	fix = 0;
	temp = ft_itoa(ft_atoi(nbr));
	if (ft_strncmp(temp, nbr, ft_strlen(nbr)))
	{
		if (nbr[fix] == '0')
		{
			free(temp);
			return (c_int(nbr + fix + 1));
		}
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	checker(int argc, char **argv, t_game *game, int count2)
{
	game->count = 1;
	while (game->count < argc && argv[game->count][0] == '-'
		&& !c_int(argv[game->count]))
	{
		count2 = 1;
		while (argv[game->count][count2])
		{
			if (argv[game->count][count2] == 'c')
				game->flag[0] = 1;
			else if (argv[game->count][count2] == 'v')
				game->flag[1] = 1;
			else if (argv[game->count][count2] == 'e')
				game->flag[5] = 1;
			else
				return (0);
			count2++;
		}
		if (!game->str && game->flag[2] == 1 && game->count + 1 < argc)
			game->str = argv[++game->count];
		else
			game->count++;
	}
	game->count = game->count - 1;
	return (1);
}

int	*init_ptr(int argc, char **argv, int count)
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
	ptr = malloc(sizeof(int) * argc - 1 - count);
	if (!(ptr))
		return (0);
	j = 0;
	i--;
	while (i > count)
		ptr[j++] = ft_atoi(argv[i--]);
	return (ptr);
}
