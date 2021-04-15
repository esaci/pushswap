/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:04:58 by esaci             #+#    #+#             */
/*   Updated: 2021/04/15 16:05:00 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

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
		if (s->ptr[i] > s->max)
			s->max = s->ptr[i];
		if (s->ptr[i] < s->min)
			s->min = s->ptr[i];
		i++;
	}
}
