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

void oper_add(t_ps *ps, int oper)
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

void oper_print(t_ps *ps)
{
    int i;

    i = 0;
    while (i < ps->len_o)
    {
        if (SA == ps->oper[i])
            ft_putstr("sa");
        else if (SB == ps->oper[i])
            ft_putstr("sb");
        else if (SS == ps->oper[i])
            ft_putstr("ss");
        else if (PA == ps->oper[i])
            ft_putstr("pa");
        else if (PB == ps->oper[i])
            ft_putstr("pb");
        else if (RA == ps->oper[i])
            ft_putstr("ra");
        else if (RB == ps->oper[i])
            ft_putstr("rb");
        else if (RR == ps->oper[i])
            ft_putstr("rr");
        else if (RRA == ps->oper[i])
            ft_putstr("rra");
        else if (RRB == ps->oper[i])
            ft_putstr("rrb");
        else if (RRR == ps->oper[i])
            ft_putstr("rrr");
        if (i != ps->len_o - 1)
            ft_putstr(DELIMETER_STRING);
        ++i;
    }
}

int ps_min(t_ps *ps)
{
    int i;
    int min;

    if (ps->len_a != 0)
    {
        min = 0;
        i = ps->len_a;
        while (--i > 0)
            if (ps->a[i].number < ps->a[min].number)
                min = i;
    }
    return (min);
}

int ps_max(t_ps *ps)
{
    int i;
    int max;

    if (ps->len_a != 0)
    {
        max = 0;
        i = ps->len_a;
        while (--i > 0)
            if (ps->a[i].number > ps->a[max].number)
                max = i;
    }
    return (max);
}

int ps_position_a(t_ps *ps, int position_b)
{
    int i;
    int answer;

    if (1 == ps->len_a) // len_a = 1 
    {
        if (ps->b[position_b].number > ps->a[0].number)
            return (0);
        else
            return (1);
    }
    else
    {
        answer = -1;
        i = ps->len_a;
        while (--i > 0)
            if (ps->a[i].number < ps->b[position_b].number && ps->b[position_b].number < ps->a[i - 1].number)
                answer = i;
        if (-1 == answer) // ps->b[position_b].number > ps->a[ps->len_a].number &&  ps->b[position_b].number < ps->a[0].number // answer = len_a
            if ( ps->b[position_b].number > ps->a[0].number &&  ps->b[position_b].number < ps->a[ps->len_a - 1].number) 
                return (ps->len_a);
            else
                return (ps_max(ps));
    }
    return (answer);
}

int weight_b_to_a(t_ps *ps, int position_b)
{
    int count;
    int position_a;
    int temp;

    count = 0;
    position_a = ps_position_a(ps, position_b);
    if (position_b != ps->len_b - 1)
        if (position_b > (ps->len_b / 2 - 1))
            count += ((ps->len_b - 1) - position_b); // rb
        else
            count += position_b + 1; // rrb
    if (position_a > (ps->len_a / 2))
        count += ps->len_a - position_a;  // ra  // and rra
    else
        count += position_a; // rra  // and ra
    return (++count); // pa
}


void ps_insert(t_ps *ps, int position_b)
{
    int count;
    int position_a;
    int temp;
    
    position_a = ps_position_a(ps, position_b);
    // printf("\nposition_b = %d; position_a = %d\n", position_b, position_a);
    if (position_b != ps->len_b - 1)
        if (position_b > (ps->len_b / 2 - 1))
        {
            temp = ((ps->len_b - 1) - position_b); // rb
            while (temp-- > 0)
                oper_add(ps, RB);
        }
        else
        {
            temp = position_b + 1; // rrb       
            while (temp-- > 0)
                oper_add(ps, RRB);
        }
    
    if (position_a > (ps->len_a / 2))
    {
        temp = ps->len_a - position_a;  // ra and rra
        count = temp;
        while (temp-- > 0)
            oper_add(ps, RA);
        oper_add(ps, PA);
    }
    else
    {
        temp = position_a; // rra  //and ra
        while (temp-- > 0)
            oper_add(ps, RRA);
        oper_add(ps, PA);
    }
}

int first_sort(t_ps *ps, int algo)
{
    int i;
    int j;
    int temp;
        // search sequence
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


int weight_on_compare(t_ps *ps)
{
    int i;
    int j;
    int temp;
    int min;

        // search sequence
    i = ps->len_a - 1;
    while (i > 0)
    {
        temp = ps->a[i].index;
        ps->a[i].weight = 1;
        j = i;
        while (--j > 0)
            if (temp > ps->a[j].index)
            {
                ps->a[i].weight += 1;
                temp = ps->a[j].index;
            }
        --i;
    }
    // ps_print(ps);
    temp = 0;
    i = ps->len_a;
    while (--i > 0)
        if (ps->a[i].weight >= ps->a[temp].weight)
            temp = i;
    
    return (ps->a[temp].weight);

}

void transporter(t_ps *ps)
{
    int i;
    int min;

    while (ps->len_b > 0)
    {
        i = ps->len_b;
        while (--i >= 0)
            ps->b[i].weight = weight_b_to_a(ps, i);
            // printf("i = %d, weight = %d \n", i,  ps->b[i].weight);
        min = 0;
        i = ps->len_b;
        while (--i > 0)
            if (ps->b[i].weight < ps->b[min].weight)
                min = i;
        // ps_print(ps);
        // printf("min = %d, weight = %d \n", min,  ps->b[min].weight);
        // getchar();
        ps_insert(ps, min);
    }
    i = ps->len_a;
    while (--i >= 0)
        if (1 == ps->a[i].index)
            break;
    if (i < ps->len_a / 2)
        while (--i >= 0)
            oper_add(ps, RRA);
    else
        while (i++ != ps->len_a)
            oper_add(ps, RA);
}

void ps_sort_insert(t_ps *ps)
{
    int i;
    int j;
    int temp;

    if (first_sort(ps, 1) > first_sort(ps, 2))
        temp = first_sort(ps, 1);
        // printf("\nweight_on_compare %d\n", temp);
    else
        temp = first_sort(ps, 2);
        // printf("\nweight_on_index %d \n", temp);
    temp = 0;
    i = ps->len_a;
    while (--i > 0)
        if (ps->a[i].weight >= ps->a[temp].weight)
            temp = i;
    // throw unnecessary to stack b
    i = temp;
    ps->a[temp].bool = 1;
    while (--i >= 0)
        if (ps->a[i].index < ps->a[temp].index)
        {
            temp = i;
            ps->a[i].bool = 1;
        }
    temp = ps->len_a;
    i = ps->len_a;
    while (--i >= 0)
        if (1 != ps->a[ps->len_a - 1].bool)
        {
            oper_add(ps, PB);
            if (ps->b[ps->len_b - 1].index > temp / 2)
                oper_add(ps, RB);
        }
        else
            oper_add(ps, RA);
    // printf("\n ps->len_a = %d, ps->len_b = %d;\n", ps->len_a, ps->len_b);
    //  ps_print(ps);
    transporter(ps);
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

int compare(int elem, int *mas, int size)
{
    int i;

    i = 1;
    while (++i < size)
        if (elem == mas[i])
            return (1);
    return (0);
}

int search(t_ps *ps, int mas[5], int size, int *rezult)
{
    int i;
    int j;

    i = -1;
    while (++i < ps->len_o - 1)
        if (mas[0] == ps->oper[i])
        {
            rezult[0] = i;
            j = i;
            while (++j < ps->len_o)
            {
                if (mas[1] == ps->oper[j])
                {
                    rezult[1] = j;
                    return (1);
                }
                else if (compare(ps->oper[j], mas, size)) //(RR == ps->oper[j] || RRA == ps->oper[j] || SA == ps->oper[j])
                    continue;
                else
                    break;
            }
        }
    return (0);
}

void replace(t_ps *ps, int *positions, int replace)
{ 
    int i;

    ps->oper[positions[0]] = replace;
    i = positions[1];
    while (++i < ps->len_o)
        ps->oper[i - 1] = ps->oper[i];
    ps->len_o -= 1;
}


void optimization(t_ps *ps)
{
    int rezult[2];
    int oper[5];

    oper[0] = RA;
    oper[1] = RB;
    oper[2] = RR;
    oper[3] = RRA;
    oper[4] = SA;
    while (search(ps, oper, 5, rezult) > 0)
        replace(ps, rezult, RR);
    oper[0] = RB;
    oper[1] = RA;
    oper[3] = RRB;
    oper[4] = SB;
    // int oper = {RB, RA, RR, RRB, SB};
    while (search(ps, oper, 5, rezult) > 0)
        replace(ps, rezult, RR);
    oper[0] = RRA;
    oper[1] = RRB;
    oper[2] = RRR;
    oper[3] = RA;
    oper[4] = SA;
    // int oper2[] = {RRA, RRB, RRR, RA, SA};
    while (search(ps, oper, 5, rezult) > 0)
        replace(ps, rezult, RRR);
    oper[0] = RRB;
    oper[1] = RRA;
    oper[3] = RB;
    oper[4] = SB;
    // int oper3[] = {RRB, RRA, RRR, RRB, SB};
    while (search(ps, oper, 5, rezult) > 0)
        replace(ps, rezult, RRR);
}

/*
 typedef struct  s_route
{
    int         elem[500];
	int         count;
}               t_route;


    t_route mas[500];
    i = 0;
    while (i < 500)
    {
        ft_bzero(mas[i], 500 * sizeof(int));
        mas[i].count = 0;
        mas[i].weight = 0;
    }



void search_route(t_ps *ps, int i, int j)
{
    mas[i].elem[j] = ps->a[i];
    mas[i].count += 1;
    while (++i < ps->len_a)
        if (ps->a[mas[i].elem[j]].number < ps->a[i].number)
        {
            search_route(ps, i, j + 1);
        }
        else
        {
            search_route(ps, i + 1, j)
        }
}
*/

void little_sort(t_ps *ps)
{
    oper_add(ps, PB);
    oper_add(ps, PB);
    if (!ps_is_sort(ps))
    {
        if (ps->a[0].number > ps->a[2].number && ps->a[0].number < ps->a[1].number)
        {
            oper_add(ps, SA);
            oper_add(ps, RA);
        }
        else if (ps->a[1].number < ps->a[2].number && ps->a[1].number > ps->a[0].number)
        {
            oper_add(ps, SA);
            oper_add(ps, RRA);
        }
        else if (ps->a[2].number < ps->a[1].number && ps->a[2].number > ps->a[0].number)
            oper_add(ps, RRA);
        else if (ps->a[2].number > ps->a[1].number && ps->a[2].number < ps->a[0].number)
            oper_add(ps, SA);
        else if (ps->a[0].number > ps->a[1].number && ps->a[0].number < ps->a[2].number)
            oper_add(ps, RA);
    }
    transporter(ps);
}


int main(int ac, char **av)
{
    int     i;
    t_ps    ps;

    ps_init(&ps);
    if (ac == 2)
    {
        ps_read_a(&ps, av[1]);
        ps_index_set(&ps);
        // ps_print(&ps);
        if (5 == ps.len_a)
            little_sort(&ps);
        else
            ps_sort_insert(&ps);
        optimization(&ps);
        oper_print(&ps);
    }
    // else
    //     write(1, "here1\n", 6);
}