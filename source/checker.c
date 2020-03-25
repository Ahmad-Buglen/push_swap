/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:53:18 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 12:53:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{
    int     i;
    t_ps    ps;

    ps_init(&ps);
    if (ac == 3)
    {
        ps_read_a(&ps, av[1]);
        ps_check(&ps, ft_strsplit(av[2], '|'));
        if (1 == ps_is_sort(&ps))
            ft_putstr("OK\n"); // \n?
        else
            ft_putstr("KO\n"); // \n?
    }
    ps_print(&ps);
}