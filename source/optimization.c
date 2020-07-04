/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:37:50 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/04 16:32:25 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			first_sort(t_ps *const ps, const int algo)
{
	int		i;
	int		j;
	int		temp;

	i = ps->len_a - 1;
	while (i > 0)
	{
		temp = ps->a[i].index;
		ps->a[i].weight = 1;
		j = i;
		while (--j > 0)
			if ((1 == algo && temp - ps->a[j].index < 3) ||
					(2 == algo && temp - ps->a[j].index))
			{
				ps->a[i].weight += 1;
				temp = ps->a[j].index;
			}
		--i;
	}
	temp = 0;
	i = ps->len_a;
	while (--i > 0)
		if (ps->a[i].weight >= ps->a[temp].weight)
			temp = i;
	return (ps->a[temp].weight);
}

static int	compare(const int elem, const int *const mas, const int size)
{
	int		i;

	i = 1;
	while (++i < size)
		if (elem == mas[i])
			return (1);
	return (0);
}

static int	search(t_ps *const ps, t_test test, const int size,
												int *const rezult)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ps->len_o - 1)
		if (test.mas[0] == ps->oper[i])
		{
			rezult[0] = i;
			j = i;
			while (++j < ps->len_o)
			{
				if (test.mas[1] == ps->oper[j])
				{
					rezult[1] = j;
					return (1);
				}
				else if (compare(ps->oper[j], test.mas, size))
					continue;
				else
					break ;
			}
		}
	return (0);
}

static void	replace(t_ps *const ps, int *const positions, const int replace)
{
	int		i;

	ps->oper[positions[0]] = replace;
	i = positions[1];
	while (++i < ps->len_o)
		ps->oper[i - 1] = ps->oper[i];
	ps->len_o -= 1;
}

void		optimization(t_ps *const ps)
{
	int		rezult[2];

	while (search(ps, (t_test){RA, RB, RR, RRA, SA}, 5, rezult) > 0)
		replace(ps, rezult, RR);
	while (search(ps, (t_test){RB, RA, RR, RRB, SB}, 5, rezult) > 0)
		replace(ps, rezult, RR);
	while (search(ps, (t_test){RRA, RRB, RRR, RA, SA}, 5, rezult) > 0)
		replace(ps, rezult, RRR);
	while (search(ps, (t_test){RRB, RRA, RRR, RRB, SB}, 5, rezult) > 0)
		replace(ps, rezult, RRR);
}
