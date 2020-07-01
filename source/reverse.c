/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:18:23 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/01 19:19:18 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ps_ra(t_ps *const ps)
{
	t_box	buf;
	int		i;

	if (ps->len_a > 1)
	{
		buf = ps->a[ps->len_a - 1];
		i = ps->len_a;
		while (--i > 0)
			ps->a[i] = ps->a[i - 1];
		ps->a[0] = buf;
	}
}

void		ps_rb(t_ps *const ps)
{
	t_box	buf;
	int		i;

	if (ps->len_b > 1)
	{
		buf = ps->b[ps->len_b - 1];
		i = ps->len_b;
		while (--i > 0)
			ps->b[i] = ps->b[i - 1];
		ps->b[0] = buf;
	}
}

void		ps_rr(t_ps *const ps)
{
	ps_ra(ps);
	ps_rb(ps);
}
