/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:12:12 by esaci             #+#    #+#             */
/*   Updated: 2021/04/26 18:12:18 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

int	c_int2(char *nbr)
{
	char	*temp;
	int		fix;

	fix = 0;
	if (nbr[0] == '-')
		fix = 1;
	temp = ft_itoa(ft_atoi(nbr));
	if (ft_strncmp(temp, nbr, ft_strlen(nbr)))
	{
		if (nbr[fix] == '0')
		{
			free(temp);
			return (c_int2(nbr + fix + 1));
		}
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	checker2(int argc, char **argv, t_game *game, int count1)
{
	int		count2;

	while (count1 < argc && argv[count1][0] == '-' && !c_int2(argv[count1]))
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

int	*readlist(int argc, char **argv, int count)
{
	int		*ptr;
	int		i;
	int		j;

	i = 1 + count;
	while (i < argc)
	{
		if (argv[i][0] == 0 || !c_int2(argv[i]))
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

void	stack_init(t_stack *s)
{
	size_t	i;

	i = 1;
	if (s->len == 0)
		return ;
	s->prem = s->ptr[s->len - 1];
	s->dern = s->ptr[0];
	s->min = s->dern;
	s->max = s->dern;
	while (i < s->len)
	{
		if (s->ptr[(int)i] > s->max)
			s->max = s->ptr[(int)i];
		if (s->ptr[(int)i] < s->min)
			s->min = s->ptr[(int)i];
		i++;
	}
}
