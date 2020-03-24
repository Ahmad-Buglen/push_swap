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

# define SIZE 1024

#include "../libft/libft.h"
#include <stdio.h>

typedef struct  s_box
{
	int         number;
	int         index;
}               t_box;

typedef struct  s_ps
{
    t_box       a[SIZE];
    t_box       b[SIZE];
	int         len_a;
	int         len_b;
}               t_ps;

void ps_init(t_ps *ps)
{
    ft_bzero(ps->a, SIZE * sizeof(t_box));
    ft_bzero(ps->b, SIZE * sizeof(t_box));
    ps->len_a = 0;
    ps->len_b = 0;
}

int ft_count_p(long long number, const int base)
{
	int	count;

	count = number < 0 ? 2 : 1;
    number = number < 0 ? -number : number;
	while (number / base)
	{
		number /= base;
		count++;
	}
	return (count);
}

void ps_print(t_ps *ps)
{
    int i;
    int size;

    size = (ps->len_a > ps->len_b) ? ps->len_a : ps->len_b;

    while (size > 0)
    {
        if (size <= ps->len_a)
        {
            ft_putnbr(ps->a[size - 1].number);
            ft_putstr(" (");
            ft_putnbr(ps->a[size - 1].index);
            ft_putstr(") ");
        }
        i = 25 - (ft_count_p(ps->a[size - 1].number, 10) + ft_count_p(ps->a[size - 1].index, 10));
        while (i-- > 0)
            write(1, " ", 1);
        if (size-- <= ps->len_b)
        {
            ft_putnbr(ps->b[size].number);
            ft_putstr(" (");
            ft_putnbr(ps->b[size].index);
            ft_putstr(" )");
        }
        write(1, "\n", 1);
    }
    ft_putstr("\\ stack a /               \\ stack b /\n");

    // if (ps->len_a > 0)
    // {
    //     printf("stack a, length %d\n", ps->len_a);
    //     i = ps->len_a - 1;
    //     while (i >= 0)
    //         printf("%d ", ps->a[i--]);
    //     printf("\n");
    // }
    // if (ps->len_b > 0)
    // {
    //     printf("stack b, length %d\n", ps->len_b);
    //     i = ps->len_b - 1;
    //     while (i >= 0)
    //         printf("%d ", ps->b[i--]);
    //     printf("\n");
    // }
}

void ps_sa(t_ps *ps)
{
    t_box buf;

    if (ps->len_a > 1)
    {
        // ft_swap
        buf = ps->a[ps->len_a - 1];
        ps->a[ps->len_a - 1] = ps->a[ps->len_a - 2];
        ps->a[ps->len_a - 2] = buf;
    }
}

void ps_sb(t_ps *ps)
{
    t_box buf;

    if (ps->len_b > 1)
    {
        // ft_swap
        buf = ps->b[ps->len_b - 1];
        ps->b[ps->len_b - 1] = ps->b[ps->len_b - 2];
        ps->b[ps->len_b - 2] = buf;
    }
}

void ps_ss(t_ps *ps)
{
    ps_sa(ps);
    ps_sb(ps);
}

void ps_pa(t_ps *ps)
{
    if (ps->len_b > 0)
        ps->a[ps->len_a++] = ps->b[--ps->len_b];
}

void ps_pb(t_ps *ps)
{
    if (ps->len_a > 0)
        ps->b[ps->len_b++] = ps->a[--ps->len_a];
}

void ps_ra(t_ps *ps)
{
    t_box buf;
    int i;

    if (ps->len_a > 1)
    {
        buf = ps->a[ps->len_a - 1];
        i = ps->len_a;
        while (--i > 0)
            ps->a[i] = ps->a[i - 1];
        ps->a[0] = buf;
    }
}

void ps_rb(t_ps *ps)
{
    t_box buf;
    int i;

    if (ps->len_b > 1)
    {
        buf = ps->b[ps->len_b - 1];
        i = ps->len_b;
        while (--i > 0)
            ps->b[i] = ps->b[i - 1];
        ps->b[0] = buf;
    }
}

void ps_rr(t_ps *ps)
{
    ps_ra(ps);
    ps_rb(ps);
}

void ps_rra(t_ps *ps)
{
    t_box buf;
    int i;

    if (ps->len_a > 1)
    {
        buf = ps->a[0];
        i = 0;
        while (i++ < ps->len_a)
            ps->a[i - 1] = ps->a[i];
        ps->a[ps->len_a - 1] = buf;
    }
}

void ps_rrb(t_ps *ps)
{
    t_box buf;
    int i;

    if (ps->len_b > 1)
    {
        buf = ps->b[0];
        i = 0;
        while (i++ < ps->len_b)
            ps->b[i - 1] = ps->b[i];
        ps->b[ps->len_b - 1] = buf;
    }
}

void ps_rrr(t_ps *ps)
{
    ps_rra(ps);
    ps_rrb(ps);
}

int ps_duplicate(t_ps *ps, int number)
{
    int i;

    i = ps->len_a;
    while (--i >= 0)
        if (number == ps->a[i].number)
            return (1);
    return (0);
}

void ps_exit(char *const message)
{
    ft_putstr(message); // error status?
    exit(0);            // param valid? 
}


int	ft_is_space(int c)
{
	if (' ' == c || '\n' == c || '\t' == c ||
        '\f' == c || '\r' == c || '\v' == c)
		return (1);
	return (0);
}

void ps_read_a(t_ps *ps, char *str)
{
    int i;
    // int count;

    i = 0;
    // count = 0;
    while(str[i])
    {
        while (ft_is_space(str[i]))
            ++i;
        if (str[i])
        {
            if (!ps_duplicate(ps, ft_atoi(str + i)))
            {
                ps->a[ps->len_a++].number = ft_atoi(str + i);
                ps_ra(ps);
            }
            else
                ps_exit("Error\n");
        }
        while (ft_isdigit(str[i]))
            ++i;
        if (!ft_isdigit(str[i]) && !ft_is_space(str[i]) && str[i])
            ps_exit("Error\n");
        // ps_print(ps);
        // i += ft_count_p(ps->a[count], 10);
        // ++count;
    }
    // ps->len_a += count;
}

void ps_check(t_ps *ps, char **oper)
{
    int i;

    i = -1;
    while(oper[++i])
        if (0 == ft_strcmp(oper[i], "sa"))
            ps_sa(ps);
        else if (0 == ft_strcmp(oper[i], "sb"))
            ps_sb(ps);
        else if (0 == ft_strcmp(oper[i], "ss"))
            ps_ss(ps);
        else if (0 == ft_strcmp(oper[i], "pa"))
            ps_pa(ps);
        else if (0 == ft_strcmp(oper[i], "pb"))
            ps_pb(ps);
        else if (0 == ft_strcmp(oper[i], "ra"))
            ps_ra(ps);
        else if (0 == ft_strcmp(oper[i], "rb"))
            ps_rb(ps);
        else if (0 == ft_strcmp(oper[i], "rr"))
            ps_rr(ps);
        else if (0 == ft_strcmp(oper[i], "rra"))
            ps_rra(ps);
        else if (0 == ft_strcmp(oper[i], "rrb"))
            ps_rrb(ps);
        else if (0 == ft_strcmp(oper[i], "rrr"))
            ps_rrr(ps);
        else
            ps_exit("Error\n");
    ft_free_dual_char(&oper);
}

int ps_is_sort(t_ps *ps)
{
    int i;

    i = ps->len_a;
    while (--i > 0)
        if (ps->a[i].number >= ps->a[i - 1].number)
            return (0);
    return (1);
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
    while (--i)
    {
        position = ps_min(ps);
        while (position++ != i)
        {
            ps_ra(ps);
            ft_putstr("ra|");
        }
        ps_pb(ps);
        ft_putstr("pb|");
    }
    i = ps->len_b;
    while (i--)
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
    while(i < ps->len_a)
    {
        max = 0;
        j = 0;
        while(j < ps->len_a)
        {
            if (0 == ps->a[j].index && ps->a[max].number < ps->a[j].number)
                max = j;
            ++j;
        }
        ps->a[max].index = i;
        ++i;
    }
}

int main(int ac, char **av)
{
    int     i;
    t_ps    ps;

    ps_init(&ps);
    // if (ac == 3)
    // {
        ps_read_a(&ps, av[1]);
        ps_index_set(&ps);
        // ps_sort_just(&ps);

    //     ps_check(&ps, ft_strsplit(av[2], '|'));
    //     if (1 == ps_is_sort(&ps))
    //         ft_putstr("OK\n"); // \n?
    //     else
    //         ft_putstr("KO\n"); // \n?
    // }
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