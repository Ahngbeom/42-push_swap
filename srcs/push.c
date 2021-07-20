/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:25:48 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 21:03:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     push(t_frame *frame, char target)
{
    t_stack     *temp;
    
    if (target == 'A')
    {
        temp = frame->b->next;
        if (frame->a != NULL)
            frame->a->prev = frame->b;
        frame->b->next = frame->a;
        frame->a = frame->b;
        frame->b = temp;
        // frame->cmd = ft_strjoin(frame->cmd, "pa\n");
        add_command(frame, "pa");
        print_stack(frame);
    }
    else if (target == 'B')
    {
        temp = frame->a->next;
        temp->prev = NULL;
        if (frame->b != NULL)
            frame->b->prev = frame->a;
        frame->a->next = frame->b;
        frame->b = frame->a;
        frame->a = temp;
        // frame->cmd = ft_strjoin(frame->cmd, "pb\n");
        add_command(frame, "pb");
        print_stack(frame);
    }
    else
        exit(1);
    return (0);
}