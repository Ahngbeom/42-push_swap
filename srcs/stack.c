/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:51:59 by bahn              #+#    #+#             */
/*   Updated: 2021/06/01 13:23:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_init(t_frame *frame, char **argv)
{
    t_stack     *stack;
    t_stack     *ptr;
    int     i;

    i = 0;
	while (argv[i + 1] != NULL)
	{
		if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
			exit(1);
		if (frame->a == NULL)
		{
			frame->a = stack;
			frame->a->prev = NULL;
		}
		else
		{
			ptr = frame->a;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = stack;
			stack->prev = ptr;
		}
		stack->element = ft_atoi(argv[i + 1]);
		stack->next = NULL;
		// print_stack(frame->a, frame->b);
		i++;
	}
}