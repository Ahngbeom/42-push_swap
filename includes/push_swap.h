/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:22:15 by bahn              #+#    #+#             */
/*   Updated: 2021/08/23 00:06:50 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define TRUE			1
# define FALSE			0

# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_S			"ss"
# define PUSH_A			"pa"
# define PUSH_B			"pb"
# define ROTATE_A		"ra"
# define ROTATE_B		"rb"
# define ROTATE_R		"rr"
# define REVERSE_ROTATE_A	"rra"
# define REVERSE_ROTATE_B	"rrb"
# define REVERSE_ROTATE_R	"rrr"

typedef	struct	s_stack	t_stack;
typedef struct	s_frame t_frame;

struct	s_stack
{
	int		element;
	t_stack *prev;
	t_stack	*next;
};

struct	s_frame
{
	t_stack	*a;
	t_stack	*b;

	int		big_pivot;
	int		small_pivot;

	char 	*cmd_list;
};

void    ft_puterr(void);
void	invalid_arg(int argc, char *argv[]);

t_frame    *frame_init();
void        frame_free(t_frame *frame);

void    stack_init(t_frame *frame, char **argv);

void    add_command(t_frame *frame, char *cmd);

int     length(t_stack *stack);
t_stack	*last_element(t_stack *stack);
t_stack	*mid_element(t_stack *stack);
int     min(t_stack *stack, int range);
int     max(t_stack *stack, int range);
int     median(t_stack *stack, int range);

int     select_pivot(t_stack *stack, int limit, double ratio);
int     select_big_pivot(t_stack *stack, int limit);
int     select_small_pivot(t_stack *stack, int limit);

int     check_asc(t_stack *stack);
int     check_desc(t_stack *stack);
void    ascending(t_frame *frame);
void    descending(t_frame *frame);

void	case_3(t_frame *frame, t_stack *stack);
void	case_5(t_frame *frame);
void	a_to_b(t_frame *frame, int count, void (*call_out_func));
void	b_to_a(t_frame *frame, int count);

void    scope_1(t_frame *frame, t_stack *stack);
void    scope_2(t_frame *frame, t_stack *stack);
void    scope_3(t_frame *frame, t_stack *stack, int range);


int    push_a(t_frame *frame);
int    push_b(t_frame *frame);

void	swap_a(t_frame *frame);
void	swap_b(t_frame *frame);
void	swap_s(t_frame *frame);

int    rotate_a(t_frame *frame);
int    rotate_b(t_frame *frame);
void    rotate_r(t_frame *frame);

int    reverse_rotate_a(t_frame *frame);
int    reverse_rotate_b(t_frame *frame);
void    reverse_rotate_r(t_frame *frame);

#endif
