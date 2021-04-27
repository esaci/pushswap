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

int		check_borne(t_stack *s, int min, int max)
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
