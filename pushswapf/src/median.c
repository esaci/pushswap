/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:48:42 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 16:48:46 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

int		count_inf(t_stack *s, size_t i,  int value)
{
	size_t	count;

	count = 0;
	while (i < s->len)
	{
		if (s->ptr[i] < value)
			count++;
		i++;
	}
	return (count);
}

int		count_sup(t_stack *s, size_t i , int value)
{
	size_t	count;

	count = 0;
	while (i < s->len)
	{
		if (s->ptr[i] > value)
			count++;
		i++;
	}
	return (count);
}

int		is_median(t_stack *stack)
{
	size_t		imin;
	size_t		count;
	size_t		reststack;

	if (stack->fsort == 1)
		imin = check_value(stack, stack->min) + 1;
	else
		imin = 0;
	reststack = stack->len - imin;
	if (reststack < 2)
		return (stack->ptr[stack->len - 1]);
	count = imin;
	while (count < stack->len)
	{
		if (reststack % 2 == 1 &&
			((count_sup(stack, imin, stack->ptr[count]))
			== count_inf(stack, imin, stack->ptr[count])))
			break ;
		else if (count_inf(stack, imin, stack->ptr[count] - 1)
			== count_sup(stack, imin, stack->ptr[count]))
			break ;
		count++;
	}
	return (stack->ptr[count]);
}
