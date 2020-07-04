/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:26:22 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/04 16:33:43 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		oper_add(t_ps *const ps, const int oper)
{
	ps->oper[ps->len_o++] = oper;
	if (SA == oper)
		ps_sa(ps);
	else if (SB == oper)
		ps_sb(ps);
	else if (SS == oper)
		ps_ss(ps);
	else if (PA == oper)
		ps_pa(ps);
	else if (PB == oper)
		ps_pb(ps);
	else if (RA == oper)
		ps_ra(ps);
	else if (RB == oper)
		ps_rb(ps);
	else if (RR == oper)
		ps_rr(ps);
	else if (RRA == oper)
		ps_rra(ps);
	else if (RRB == oper)
		ps_rrb(ps);
	else if (RRR == oper)
		ps_rrr(ps);
}

static void	oper_print(t_ps *const ps, int i)
{
	while (++i < ps->len_o)
		if (SA == ps->oper[i])
			ft_putstr("sa\n");
		else if (SB == ps->oper[i])
			ft_putstr("sb\n");
		else if (SS == ps->oper[i])
			ft_putstr("ss\n");
		else if (PA == ps->oper[i])
			ft_putstr("pa\n");
		else if (PB == ps->oper[i])
			ft_putstr("pb\n");
		else if (RA == ps->oper[i])
			ft_putstr("ra\n");
		else if (RB == ps->oper[i])
			ft_putstr("rb\n");
		else if (RR == ps->oper[i])
			ft_putstr("rr\n");
		else if (RRA == ps->oper[i])
			ft_putstr("rra\n");
		else if (RRB == ps->oper[i])
			ft_putstr("rrb\n");
		else if (RRR == ps->oper[i])
			ft_putstr("rrr\n");
}

static void	sort_tree(t_ps *const ps)
{
	if (ps->a[0].number > ps->a[2].number && ps->a[0].number < ps->a[1].number)
	{
		oper_add(ps, SA);
		oper_add(ps, RA);
	}
	else if (ps->a[1].number < ps->a[2].number &&
					ps->a[1].number > ps->a[0].number)
	{
		oper_add(ps, SA);
		oper_add(ps, RRA);
	}
	else if (ps->a[2].number < ps->a[1].number &&
					ps->a[2].number > ps->a[0].number)
		oper_add(ps, RRA);
	else if (ps->a[2].number > ps->a[1].number &&
					ps->a[2].number < ps->a[0].number)
		oper_add(ps, SA);
	else if (ps->a[0].number > ps->a[1].number &&
					ps->a[0].number < ps->a[2].number)
		oper_add(ps, RA);
}

static void	little_sort(t_ps *const ps)
{
	while (ps->len_a > 3)
		oper_add(ps, PB);
	if (2 == ps->len_a)
		oper_add(ps, SA);
	else
		sort_tree(ps);
	if (ps->len_b != 0)
		transporter(ps);
}

int			main(int ac, char **av)
{
	t_ps	ps;

	ft_bzero(&ps, sizeof(t_ps));
	if (ac > 1)
	{
		ps_read_a(&ps, ac, av);
		ps_index_set(&ps);
		if (!ps_is_sort(&ps))
		{
			if (5 >= ps.len_a)
				little_sort(&ps);
			else
				ps_sort_insert(&ps);
			optimization(&ps);
			oper_print(&ps, -1);
		}
	}
}
