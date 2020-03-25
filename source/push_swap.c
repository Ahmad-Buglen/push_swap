/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 16:45:18 by marvin            #+#    #+#             */
/*   Updated: 2020/03/21 16:45:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ps_min(t_ps *ps)
{
    int i;
    int min;

    if (ps->len_a != 0)
    {
        min = 0;
        i = ps->len_a;
        while (--i > 0)
            if (ps->a[i].number < ps->a[i - 1].number)
                min = i;
    }
    return (min);
}

void ps_sort_just(t_ps *ps)
{
    int i;
    int position;

    i = ps->len_a;
    while (--i > 0)
    {
        position = ps_min(ps);
        if (position > (ps->len_a / 2 - 1))
            while (position++ != i)
            {
                ps_ra(ps);
                ft_putstr("ra|");
            }
        else
            while (position-- != -1)
            {
                ps_rra(ps);
                ft_putstr("rra|");
            }
        ps_pb(ps);
        ft_putstr("pb|");
    }
    i = ps->len_b;
    while (i-- > 0)
    {
        ps_pa(ps);
        ft_putstr("pa|");
    }
}

void ps_index_set(t_ps *ps)
{
    int i;
    int j;
    int max;

    i = 0;
    while(++i <= ps->len_a)
    {
        // max = i;
        j = 0;
        while (j < ps->len_a && 0 != ps->a[j].index)
            ++j;
        max = j;
        while(++j < ps->len_a)
        {
            if (0 == ps->a[j].index && ps->a[max].number < ps->a[j].number)
                max = j;
        }
        ps->a[max].index = i;
        // ++i;
    }
}

int main(int ac, char **av)
{
    int     i;
    t_ps    ps;

    ps_init(&ps);
    if (ac == 2)
    {
        
        ps_read_a(&ps, av[1]);
        
    // ps_print(&ps);
        ps_index_set(&ps);
        
    ps_print(&ps);
        ps_sort_just(&ps);

        // ps_check(&ps, ft_strsplit(av[2], '|'));
        // if (1 == ps_is_sort(&ps))
        //     ft_putstr("OK\n"); // \n?
        // else
        //     ft_putstr("KO\n"); // \n?
    }
    ps_print(&ps);
    // ps_ra(&ps);
    // ps_pb(&ps);
    // ps_pb(&ps);
    // ps_pb(&ps);

    // ps_print(&ps);

    // ps_rrb(&ps);    
    // ps_rrb(&ps);
    // // ps_rrb(&ps);

    // ps_print(&ps);
    // ps_pa(&ps);
    // ps_ss(&ps);
    // ps_sb(&ps);
    // ps_print(&ps);
}