/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:53:08 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 12:53:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>


# define SIZE 1024

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

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

void ps_sa(t_ps *const ps);
void ps_sb(t_ps *const ps);
void ps_ss(t_ps *const ps);
void ps_pa(t_ps *const ps);
void ps_pb(t_ps *const ps);
void ps_ra(t_ps *const ps);
void ps_rb(t_ps *const ps);
void ps_rr(t_ps *const ps);
void ps_rra(t_ps *const ps);
void ps_rrr(t_ps *const ps);
void ps_rrb(t_ps *const ps);
void ps_init(t_ps *const ps);		//const
void ps_print(t_ps *const ps);	
void ps_read_a(t_ps *ps, char *const str);	
void ps_check(t_ps *const ps, char ** oper);	
int ps_is_sort(t_ps *const ps);	
int ps_duplicate(t_ps *const ps, const int number);
void ps_exit(char *const message);
int	ft_is_space(const int c);

#endif