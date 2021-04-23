/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:35:05 by esaci             #+#    #+#             */
/*   Updated: 2021/04/23 16:35:06 by esaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bibz/libpush.h"

void	clean(t_stack *src, t_stack *dest)
{
	while (src->size > 0)
	{
		rotate_to(src, get_closest_value(src, src->min, src->max));
		push(src, dest);
		add_to_sort(dest, src);
	}
}

void	quick_b(t_stack *a, t_stack *b, int inter_min, int inter_max)
{
	if (inter_min >= inter_max)
		return ;
	while (check_borne(b, inter_min, b->max) == 1 && b->size > 13)
	{
		if ((b->first >= inter_min && b->first <= b->max) || b->first == b->min)
		{
			push(b, a);
			add_to_sort(a, b);
		}
		else
			rotate(b);
	}
	clean(b, a);
	quick_a(a, b, a->sort.max + 1, inter_max);
}

void	quick_a(t_game *game, int min, int bornemax)
{
	if (min >= bornemax)
		return ;
	while (check_borne(a, min, bornemax) == 1)
	{
		if (a->first >= min && a->first <= bornemax)
			push(a, b);
		else
			rotate(a);
	}
	if (a->sort.active == true)
	{
		while (a->last != a->sort.max)
			reverse(a);
	}
	quick_b(a, b, get_median(b), bornemax);
}

void	add_to_sort(t_stack *a, t_stack *b)
{
	size_t	i;

	if ((a->first > b->min && b->size > 0) || is_sort(a))
		return ;
	if (a->first == a->min)
	{
		a->sort.active = true;
		rotate(a);
		return (add_to_sort(a, b));
	}
	i = get_index(a, a->min) + 1;
	while (i < a->size - 1)
	{
		if (a->list[i] < a->first)
			return ;
		i++;
	}
	rotate(a);
	a->sort.max = a->last;
	return (add_to_sort(a, b));
}

int		get_closest_value(t_stack *stack, int a, int b)
{
	size_t	index_a;
	size_t	index_b;

	index_a = get_index(stack, a);
	index_b = get_index(stack, b);
	if (index_a < stack->size / 2)
		index_a += 1;
	else
		index_a = stack->size - index_a - 1;
	if (index_b < stack->size / 2)
		index_b += 1;
	else
		index_b = stack->size - index_b - 1;
	if (index_b < index_a)
		return (b);
	return (a);
}

void	tech_pquinze(game)
{
	int		bornemax;
	int		min;

	a->fsort = 0;
	b->fsort = 0;
	min = a->min;
	while (is_good(game) < 1)
	{
		bornemax = is_median(a);
		if (bornemax == min)
		{
			if (a->prem > a->ptr[a->len - 2])
				updatelist(game, "sa");
			updatelist(game, "ra");
			updatelist(game, "ra");
			return ;
		}
		quick_a(game, min, bornemax);
		min = a->fmax + 1;
	}
}
