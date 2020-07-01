/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:49:51 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/01 19:27:24 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_check(t_ps *const ps, char *const *const oper)
{
	if (0 == ft_strcmp(*oper, "sa"))
		ps_sa(ps);
	else if (0 == ft_strcmp(*oper, "sb"))
		ps_sb(ps);
	else if (0 == ft_strcmp(*oper, "ss"))
		ps_ss(ps);
	else if (0 == ft_strcmp(*oper, "pa"))
		ps_pa(ps);
	else if (0 == ft_strcmp(*oper, "pb"))
		ps_pb(ps);
	else if (0 == ft_strcmp(*oper, "ra"))
		ps_ra(ps);
	else if (0 == ft_strcmp(*oper, "rb"))
		ps_rb(ps);
	else if (0 == ft_strcmp(*oper, "rr"))
		ps_rr(ps);
	else if (0 == ft_strcmp(*oper, "rra"))
		ps_rra(ps);
	else if (0 == ft_strcmp(*oper, "rrb"))
		ps_rrb(ps);
	else if (0 == ft_strcmp(*oper, "rrr"))
		ps_rrr(ps);
	else
		ft_exit_fail("Error\n");
}

int			main(int ac, char **av)
{
	int		i;
	t_ps	ps;
	char	*oper;
	int		ret;

	ft_bzero(&ps, sizeof(t_ps));
	if (ac > 1)
	{
		ps_read_a(&ps, ac, av);
		while ((ret = get_next_line(0, &oper)) > 0)
		{
			ps_check(&ps, &oper);
			free(oper);
		}
		if (1 == ps_is_sort(&ps))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
}
