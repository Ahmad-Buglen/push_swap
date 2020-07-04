/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:24:18 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/04 16:35:13 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ps_is_sort(t_ps *const ps)
{
	int		i;

	if (ps->len_b != 0)
		return (0);
	i = ps->len_a;
	while (--i > 0)
		if (ps->a[i].number >= ps->a[i - 1].number)
			return (0);
	return (1);
}

static int	ps_duplicate(t_ps *const ps, const int number)
{
	int		i;

	i = ps->len_a;
	while (--i >= 0)
		if (number == ps->a[i].number)
			return (1);
	return (0);
}

static int	length_digit(const char *const str)
{
	int		i;
	int		j;

	j = 0;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' ||
			str[j] == '\f' || str[j] == '\r' || str[j] == '\v')
		++j;
	j += (str[j] == '-' || str[j] == '+') ? 1 : 0;
	i = 0;
	while (ft_isdigit(str[j + i]))
		++i;
	return (i);
}

static void	add_elem(t_ps *const ps, const char *const str)
{
	if (!ps_duplicate(ps, ft_atol(str)) &&
			ps->len_a < SIZE &&
			length_digit(str) <= LEN_INT &&
			!((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1))) &&
			(ft_atol(str) >= MIN_INT && ft_atol(str) <= MAX_INT))
	{
		ps->a[ps->len_a++].number = ft_atol(str);
		ps_ra(ps);
	}
	else
		ft_exit_fail("Error\n");
}

void		ps_read_a(t_ps *const ps, const int ac, char *const *const av)
{
	int		i;

	if (ac > 2)
	{
		i = 0;
		while (ac > ++i)
			add_elem(ps, av[i]);
	}
	else
	{
		i = 0;
		while (av[1][i])
		{
			while (ft_is_space(av[1][i]))
				++i;
			if (av[1][i])
				add_elem(ps, av[1] + i);
			while (ft_isdigit(av[1][i]) || '-' == av[1][i] || '+' == av[1][i])
				++i;
		}
	}
}
