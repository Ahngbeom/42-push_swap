/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:29 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 21:03:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void       swap(t_frame *frame, char target)
{
    t_stack     *temp;

    if (target == 'A')
    {
        temp = frame->a->next;
        frame->a->prev = temp;
        frame->a->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->a;
        frame->a = temp;
       
        // frame->cmd = ft_strjoin(frame->cmd, "sa\n");
        add_command(frame, "sa");
        print_stack(frame);
    }
    else if (target == 'B')
    {
        temp = frame->b->next;
        frame->b->prev = temp;
        frame->b->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->b;
        frame->b = temp;
        // frame->cmd = ft_strjoin(frame->cmd, "sb\n");
        add_command(frame, "sb");
        print_stack(frame);
    }
    else if (target == 'S')
    {
        temp = frame->a->next;
        frame->a->prev = temp;
        frame->a->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->a;
        frame->a = temp;

        temp = frame->b->next;
        frame->b->prev = temp;
        frame->b->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->b;
        frame->b = temp;

        // frame->cmd = ft_strjoin(frame->cmd, "ss\n");
        add_command(frame, "ss");
        print_stack(frame);
    }
    else
        exit(1);
}