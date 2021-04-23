/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:19:37 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 14:19:39 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_show(char *move, int fd)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		while (tab[i].nb > 0)
		{
			write(fd, tab[i].move, ft_strlen(tab[i].move));
			write(fd, "\n", 1);
			tab[i].nb--;
		}
		i++;
	}
	if (move)
	{
		write(fd, move, ft_strlen(move));
		write(fd, "\n", 1);
	}
}
