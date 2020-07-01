/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:17:08 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/01 19:19:26 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ps_sa(t_ps *const ps)
{
	t_box	buf;

	if (ps->len_a > 1)
	{
		buf = ps->a[ps->len_a - 1];
		ps->a[ps->len_a - 1] = ps->a[ps->len_a - 2];
		ps->a[ps->len_a - 2] = buf;
	}
}

void		ps_sb(t_ps *const ps)
{
	t_box	buf;

	if (ps->len_b > 1)
	{
		buf = ps->b[ps->len_b - 1];
		ps->b[ps->len_b - 1] = ps->b[ps->len_b - 2];
		ps->b[ps->len_b - 2] = buf;
	}
}

void		ps_ss(t_ps *const ps)
{
	ps_sa(ps);
	ps_sb(ps);
}

void		ps_pa(t_ps *const ps)
{
	if (ps->len_b > 0)
		ps->a[ps->len_a++] = ps->b[--ps->len_b];
}

void		ps_pb(t_ps *const ps)
{
	if (ps->len_a > 0)
		ps->b[ps->len_b++] = ps->a[--ps->len_a];
}
