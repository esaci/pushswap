/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:12:09 by esaci             #+#    #+#             */
/*   Updated: 2021/07/09 11:12:10 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

void 			freechar(char **argv2)
{
	int	count;

	count = 0;
	while (argv2[count])
	{
		free(argv2[count]);
		count++;
	}
	free(argv2);
}

char	**malloqueur(char **argv)
{
	int		count;
	int		count2;
	int		count3;
	char	**argv2;

	count = 0;
	count3 = 0;
	while (argv[count])
	{
		count2 = 0;
		while (argv[count][count2])
		{
			if (argv[count][count2] == ' ')
				count3++;
			count2++;
		}
		count++;
		count3++;
	}
	count3++;
	argv2 = malloc(sizeof(char *) * count3);
	if (!argv2)
		exit (1);
	argv2[count3 - 1] = NULL;
	return (argv2);
}

char	**replace(char **argv, t_game *game)
{
	int		count;
	int		count2;
	int		count4;
	char	**argv3;
	char	**argv2;

	game->count = 0;
	count2 = 0;
	argv2 = malloqueur(argv);
	count = 0;
	while (argv[count])
	{
		argv3 = ft_split(argv[count], ' ');
		count4 = 0;
		while (argv3[count4])
		{
			argv2[count2] = argv3[count4];
			count2++;
			count4++;
		}
		free(argv3);
		count++;
	}
	return (argv2);
}

char	**ft_show(char **str, t_game *game)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	game->argc = count;
	return (str);
}

char	**game_char(int argc, char **argv, t_game *game)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (argv[count])
	{
		count2 = 0;
		while (argv[count][count2])
		{
			if (argv[count][count2] == ' ')
			{
				return (ft_show(replace(argv, game), game));
			}
			count2++;
		}
		count++;
	}
	game->argc = argc;
	return (argv);
}
