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

typedef struct  s_ps
{
    int         a[SIZE];
    int         b[SIZE];
	int         len_a;
	int         len_b;
}               t_ps;

void ps_init(t_ps *ps)
{
    ft_bzero(ps->a, SIZE);
    ft_bzero(ps->b, SIZE);
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

    while (--size >= 0)
    {
        if (size <= ps->len_a && ps->len_a != 0)
            ft_putnbr(ps->a[size]);
        i = 13 - ft_count_p(ps->a[size], 10);
        while (i-- > 0)
            write(1, " ", 1);
        if (size <= ps->len_b && ps->len_b != 0)
            ft_putnbr(ps->b[size]);
        write(1, "\n", 1);
    }
    ft_putstr("\\\\ stack a //\\\\ stack b //\n");

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
    int buf;

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
    int buf;

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
    int buf;
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
    int buf;
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
    int buf;
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
    int buf;
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
        if (number == ps->a[i])
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

void pw_read_a(t_ps *ps, char *str)
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
                ps->a[ps->len_a++] = ft_atoi(str + i);
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

int main(int ac, char **av)
{
    int     i;
    t_ps    ps;

    ps_init(&ps);
    if (ac == 2)
    {
        pw_read_a(&ps, av[1]);
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