/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:22:15 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 20:33:04 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
typedef struct	s_command t_command;
typedef struct	s_frame t_frame;

struct	s_stack
{
	int		element;
	t_stack *prev;
	t_stack	*next;
};

struct	s_command
{
	char		*cmd;
	t_command	*prev;
	t_command	*next;
};

struct	s_frame
{
	t_stack	*a;
	t_stack	*b;

	int		pivot_a;
	int		pivot_b;

	t_command	*cmd_list;
};

void    print_stack(t_frame *frame);
void    print_command(t_command *cmd_list);

int     isInteger(char *str);
int     invalid_arg(int argc, char *argv[]);

t_frame    *frame_init();
void        frame_free(t_frame *frame);

void    stack_init(t_frame *frame, char **argv);

void    add_command(t_frame *frame, char *cmd);

int     length(t_stack *stack);
t_stack     *last_element(t_stack *stack);
int     min(t_stack *stack);
int     max(t_stack *stack);
int     median(t_stack *stack, int size);

int     check_asc(t_stack *stack);
int     check_desc(t_stack *stack);
void    ascending(t_frame *frame);
void    pop_in_the_b(t_frame *frame);

void	case_3(t_frame *frame);
void	case_5(t_frame *frame);
void	case_other(t_frame *frame);

void       swap(t_frame *frame, char target);

int     push(t_frame *frame, char target);
void	less_than_to_pivot(t_frame *frame);
void    greater_than_or_eq_to_pivot(t_frame *frame);

void    rotate(t_frame *frame, char target);
void    reverse_rotate(t_frame *frame, char target);

#endif
