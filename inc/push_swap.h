/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:43:42 by danz              #+#    #+#             */
/*   Updated: 2025/12/04 19:44:08 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*first;
	t_list	*last;
}	t_stack;	

t_stack	*pars(int argc, char **argv);
t_stack	*pars_one_str(int argc, char **argv);
short	is_ok(char *arg);
void	normalize(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	algo_35(t_stack *a, t_stack *b);
void	algorithm(t_stack *a, t_stack *b, int size);
short	is_sorted(t_stack *a);
int		max_pos(t_stack *b);

#endif