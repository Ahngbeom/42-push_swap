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

void       swap_a(t_frame *frame)
{
    t_stack     *temp;

    if (length(frame->b) >= 2 && frame->b->element < frame->b->next->element)
        swap_s(frame);
    else
    {
        temp = frame->a->next;
        frame->a->prev = temp;
        frame->a->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->a;
        frame->a = temp;
        add_command(frame, "sa");
        print_stack(frame);
    }
}

void       swap_b(t_frame *frame)
{
    t_stack     *temp;

    if (length(frame->a) >= 2 && frame->a->element > frame->a->next->element)
        swap_s(frame);
    else
    {
        temp = frame->b->next;
        frame->b->prev = temp;
        frame->b->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->b;
        frame->b = temp;
        add_command(frame, "sb");
        print_stack(frame);
    }
}

void       swap_s(t_frame *frame)
{
    t_stack     *temp;

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
    add_command(frame, "ss");
    print_stack(frame);
}