/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danzamor <danzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:36:58 by danzamor          #+#    #+#             */
/*   Updated: 2025/12/04 19:43:52 by danzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*first;
	t_list	*last;
}	t_stack;	

typedef struct s_nb
{
	int	pos;
	int	rota;
	int	rotb;
	int	total;
}	t_nb;

t_stack	*pars(int argc, char **argv);
t_stack	*pars_one_str(int argc, char **argv);
short	is_ok(char *arg);
void	normalize(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif