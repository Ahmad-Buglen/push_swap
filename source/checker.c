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
    char    *oper;
    int ret;

    ps_init(&ps);
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

        // ps_print(&ps);
    }
    // else
    //     ps_exit("Error\n");
}