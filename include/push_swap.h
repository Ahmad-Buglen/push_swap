/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:52:54 by dphyliss          #+#    #+#             */
/*   Updated: 2020/07/01 14:52:54 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

# define DELIMETER_CHAR '\n'
# define DELIMETER_STRING "\n"

# define SIZE 1024
# define BUFF 1024
# define OPER 1000000
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define LEN_INT 11
# define FAILURE_EXIT 1

# define STACK_A 1
# define STACK_B 2

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
	int			bool;
	int			weight;
}               t_box;

typedef struct  s_ps
{
    t_box       a[SIZE];
    t_box       b[SIZE];
	int         len_a;
	int         len_b;
	int			oper[OPER];
	int			len_o;
}               t_ps;

 typedef struct	s_test 
{
	int			mas[5];
}				t_test;


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


void	ps_read_a(t_ps *const ps, const int ac, char *const *const av);
int		ps_is_sort(t_ps *const ps);

void	oper_add(t_ps *const ps, const int oper);
void	transporter(t_ps *const ps);
void	ps_sort_insert(t_ps *const ps);
int		ps_position_a(t_ps *const ps, const int position_b);
int		weight_b_to_a(t_ps *const ps, const int position_b);
int		ps_max(t_ps *const ps);
void	ps_index_set(t_ps *const ps);
void	optimization(t_ps *const ps);
int		first_sort(t_ps *const ps, const int algo);

#endif