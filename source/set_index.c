/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:39:13 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/02 16:31:35 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ps_position_a(t_ps *const ps, const int position_b)
{
	int	i;
	int	answer;

	if (1 == ps->len_a)
		return (ps->b[position_b].number > ps->a[0].number) ? 0 : 1;
	else
	{
		answer = -1;
		i = ps->len_a;
		while (--i > 0)
			if (ps->a[i].number < ps->b[position_b].number &&
					ps->b[position_b].number < ps->a[i - 1].number)
				answer = i;
		if (-1 == answer)
		{
			if (ps->b[position_b].number > ps->a[0].number &&
					ps->b[position_b].number < ps->a[ps->len_a - 1].number)
				return (ps->len_a);
			else
				return (ps_max(ps));
		}
	}
	return (answer);
}

int		weight_b_to_a(t_ps *const ps, const int position_b)
{
	int	count;
	int	position_a;
	int	temp;

	count = 0;
	position_a = ps_position_a(ps, position_b);
	if (position_b != ps->len_b - 1)
	{
		if (position_b > (ps->len_b / 2 - 1))
			count += ((ps->len_b - 1) - position_b);
		else
			count += position_b + 1;
	}
	if (position_a > (ps->len_a / 2))
		count += ps->len_a - position_a;
	else
		count += position_a;
	return (++count);
}

// int		ps_min(t_ps *const ps)
// {
// 	int	i;
// 	int	min;

// 	if (ps->len_a != 0)
// 	{
// 		min = 0;
// 		i = ps->len_a;
// 		while (--i > 0)
// 			if (ps->a[i].number < ps->a[min].number)
// 				min = i;
// 	}
// 	return (min);
// }


int		ps_max(t_ps *const ps)
{
	int	i;
	int	max;

	if (ps->len_a != 0)
	{
		max = 0;
		i = ps->len_a;
		while (--i > 0)
			if (ps->a[i].number > ps->a[max].number)
				max = i;
	}
	return (max);
}

void	ps_index_set(t_ps *const ps)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	while (++i <= ps->len_a)
	{
		j = 0;
		while (j < ps->len_a && 0 != ps->a[j].index)
			++j;
		max = j;
		while (++j < ps->len_a)
		{
			if (0 == ps->a[j].index && ps->a[max].number < ps->a[j].number)
				max = j;
		}
		ps->a[max].index = i;
	}
}
