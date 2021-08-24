/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:29 by bahn              #+#    #+#             */
/*   Updated: 2021/08/24 16:19:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    print_stack(t_frame *frame);

void     swap_a(t_frame *frame)
{
    t_stack     *temp;
    
    temp = frame->a->next;
    frame->a->prev = temp;
    frame->a->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = frame->a;
    temp->prev = NULL;
    temp->next = frame->a;
    frame->a = temp;
    add_command(frame, "sa");
    print_stack(frame);
}

void       swap_b(t_frame *frame)
{
    t_stack     *temp;

    temp = frame->b->next;
    frame->b->prev = temp;
    frame->b->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = frame->b;
    temp->prev = NULL;
    temp->next = frame->b;
    frame->b = temp;
    add_command(frame, "sb");
    print_stack(frame);
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