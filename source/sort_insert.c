/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:43:54 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/02 19:04:17 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


// int		weight_on_compare(t_ps *const ps)
// {
// 	int	i;
// 	int	j;
// 	int	temp;
// 	int	min;

// 	i = ps->len_a - 1;
// 	while (i > 0)
// 	{
// 		temp = ps->a[i].index;
// 		ps->a[i].weight = 1;
// 		j = i;
// 		while (--j > 0)
// 			if (temp > ps->a[j].index)
// 			{
// 				ps->a[i].weight += 1;
// 				temp = ps->a[j].index;
// 			}
// 		--i;
// 	}
// 	temp = 0;
// 	i = ps->len_a;
// 	while (--i > 0)
// 		if (ps->a[i].weight >= ps->a[temp].weight)
// 			temp = i;
// 	return (ps->a[temp].weight);
// }

static void	ps_insert(t_ps *const ps, const int position_b)
{
	int		count;
	int		position_a;
	int		temp;

	position_a = ps_position_a(ps, position_b);
	if (position_b != ps->len_b - 1)
	{
		temp = (position_b > (ps->len_b / 2 - 1)) ?
				((ps->len_b - 1) - position_b) : position_b + 1;
		while (temp-- > 0)
			if (position_b > (ps->len_b / 2 - 1))
				oper_add(ps, RB);
			else
				oper_add(ps, RRB);
	}
	temp = (position_a > (ps->len_a / 2)) ? ps->len_a - position_a :
															position_a;
	while (temp-- > 0)
		if (position_a > (ps->len_a / 2))
			oper_add(ps, RA);
		else
			oper_add(ps, RRA);
	oper_add(ps, PA);
}

void		transporter(t_ps *const ps)
{
	int		i;
	int		min;

	while (ps->len_b > 0)
	{
		i = ps->len_b;
		while (--i >= 0)
			ps->b[i].weight = weight_b_to_a(ps, i);
		min = 0;
		i = ps->len_b;
		while (--i > 0)
			if (ps->b[i].weight < ps->b[min].weight)
				min = i;
		ps_insert(ps, min);
	}
	i = ps->len_a;
	while (--i >= 0)
		if (1 == ps->a[i].index)
			break ;
	if (i < ps->len_a / 2)
		while (--i >= 0)
			oper_add(ps, RRA);
	else
		while (i++ != ps->len_a)
			oper_add(ps, RA);
}

static void	ps_sort_insert_two(t_ps *const ps)
{
	int		i;
	int		temp;

	temp = ps->len_a;
	i = ps->len_a;
	while (--i >= 0)
		if (1 != ps->a[ps->len_a - 1].bool)
		{
			oper_add(ps, PB);
			if (ps->b[ps->len_b - 1].index > temp / 2)
				oper_add(ps, RB);
		}
		else
			oper_add(ps, RA);
	transporter(ps);
}

void	ps_sort_insert(t_ps *const ps)
{
	int	i;
	int	temp;

	temp = (first_sort(ps, 1) > first_sort(ps, 2)) ? first_sort(ps, 1) :
														first_sort(ps, 2);
	temp = 0;
	i = ps->len_a;
	while (--i > 0)
		if (ps->a[i].weight >= ps->a[temp].weight)
			temp = i;
	i = temp;
	ps->a[temp].bool = 1;
	while (--i >= 0)
		if (ps->a[i].index < ps->a[temp].index)
		{
			temp = i;
			ps->a[i].bool = 1;
		}
	ps_sort_insert_two(ps);
}
