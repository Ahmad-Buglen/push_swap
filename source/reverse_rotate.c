/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:18:49 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/04 16:21:38 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ps_rra(t_ps *const ps)
{
	t_box	buf;
	int		i;

	if (ps->len_a > 1)
	{
		buf = ps->a[0];
		i = 0;
		while (i++ < ps->len_a)
			ps->a[i - 1] = ps->a[i];
		ps->a[ps->len_a - 1] = buf;
	}
}

void		ps_rrb(t_ps *const ps)
{
	t_box	buf;
	int		i;

	if (ps->len_b > 1)
	{
		buf = ps->b[0];
		i = 0;
		while (i++ < ps->len_b)
			ps->b[i - 1] = ps->b[i];
		ps->b[ps->len_b - 1] = buf;
	}
}

void		ps_rrr(t_ps *const ps)
{
	ps_rra(ps);
	ps_rrb(ps);
}
