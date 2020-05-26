/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:28:56 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 15:28:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ps_init(t_ps *const ps)
{
    ft_bzero(ps->a, SIZE * sizeof(t_box));
    ft_bzero(ps->b, SIZE * sizeof(t_box));
    ft_bzero(ps->oper, BUFF * sizeof(int));
    ps->len_a = 0;
    ps->len_b = 0;
    ps->len_o = 0;
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

void ps_print(t_ps *const ps)
{
    int i;
    int size;

    size = (ps->len_a > ps->len_b) ? ps->len_a : ps->len_b;

        printf("\n--------------------------------------\n");
    while (--size >= 0)
    {
        printf("|%3d| ", size);
        // ft_putnbr(size - 1);
        // ft_putstr(" | ");
        if (size < ps->len_a)
            printf("%7d (%d) [%d] %s", ps->a[size].number, ps->a[size].index, ps->a[size].weight,
                    1 == ps->a[size].bool ? "t" : "f");
        else
            printf("                    ");
        if (size < ps->len_b)
            printf("  %7d (%d) [%d] %s", ps->b[size].number, ps->b[size].index, ps->b[size].weight,
                    1 == ps->a[size].bool ? "t" : "f");
        else
            printf("                    ");
        // {
        //     ft_putnbr(ps->a[size - 1].number);
        //     ft_putstr(" (");
        //     ft_putnbr(ps->a[size - 1].index);
        //     ft_putstr(") ");
        //     if (1 == ps->a[size - 1].bool)
        //         ft_putstr("true  ");
        //     else
        //         ft_putstr("false ");
        //     ft_putstr("|");
        //     ft_putnbr(ps->a[size - 1].weight);
        //     ft_putstr("| ");
        // }
        // else
        // {
        //     ft_putstr("                    ");
        // }
        // i = 25 - (ft_count_p(ps->a[size - 1].number, 10) + ft_count_p(ps->a[size - 1].index, 10));
        // while (i-- > 0)
        //     write(1, " ", 1);
        // {
        //     ft_putnbr(size);
        //     ft_putstr(" - ");
        //     ft_putnbr(ps->b[size].number);
        //     ft_putstr(" (");
        //     ft_putnbr(ps->b[size].index);
        //     ft_putstr(") ");
        //     if (1 == ps->b[size].bool)
        //         ft_putstr("true  ");
        //     else
        //         ft_putstr("false ");
        //     ft_putstr("|");
        //     ft_putnbr(ps->b[size].weight);
        //     ft_putstr("| ");
        // }
        printf("\n");
    }
    printf("--------------------------------------\n");
    printf("\\ stack a /           \\ stack b /\n");

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

void ps_sa(t_ps *const ps)
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

void ps_sb(t_ps *const ps)
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

void ps_ss(t_ps *const ps)
{
    ps_sa(ps);
    ps_sb(ps);
}

void ps_pa(t_ps *const ps)
{
    if (ps->len_b > 0)
        ps->a[ps->len_a++] = ps->b[--ps->len_b];
}

void ps_pb(t_ps *const ps)
{
    if (ps->len_a > 0)
        ps->b[ps->len_b++] = ps->a[--ps->len_a];
}

void ps_ra(t_ps *const ps)
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

void ps_rb(t_ps *const ps)
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

void ps_rr(t_ps *const ps)
{
    ps_ra(ps);
    ps_rb(ps);
}


void ps_rra(t_ps *const ps)
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

void ps_rrb(t_ps *const ps)
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

void ps_rrr(t_ps *const ps)
{
    ps_rra(ps);
    ps_rrb(ps);
}

int ps_duplicate(t_ps *const ps, const int number)
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


int	ft_is_space(const int c)
{
	if (' ' == c || '\n' == c || '\t' == c ||
        '\f' == c || '\r' == c || '\v' == c)
		return (1);
	return (0);
}

void ps_read_a(t_ps *const ps, char *const str)
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
                // write(1, "here\n", 5);
                // ft_putnbr(i);
                //  write(1, "\n", 1);
                ps->a[ps->len_a++].number = ft_atoi(str + i);
                
                ps_ra(ps);
            }
            else
                ps_exit("Error1\n");
        }
        
        while (ft_isdigit(str[i]) || '-' == str[i] || '+' == str[i])
            ++i;
            
        if ((ft_isdigit(str[i]) || '-' == str[i] || '+' == str[i]) && !ft_is_space(str[i]) && str[i])
            ps_exit("Error2\n");
        // ps_print(ps);
        // i += ft_count_p(ps->a[count], 10);
        // ++count;
    }
    // ps->len_a += count;
}

void ps_check(t_ps *const ps, char ** oper)
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

int ps_is_sort(t_ps *const ps)
{
    int i;

    i = ps->len_a;
    while (--i > 0)
        if (ps->a[i].number >= ps->a[i - 1].number)
            return (0);
    if (ps->len_b != 0)
        return (0);
    return (1); 
}
