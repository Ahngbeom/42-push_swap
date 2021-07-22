/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:37 by bahn              #+#    #+#             */
/*   Updated: 2021/07/22 13:45:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_a(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2)
    {
        printf("rra : 해당 연산을 수행할 수 없습니다.\n");
        return ;
    }
    temp = last_element(frame->a);
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = frame->a;
    frame->a->prev = temp;
    frame->a = temp;
    add_command(frame, "rra");
    print_stack(frame);
}

void    reverse_rotate_b(t_frame *frame)
{
    t_stack *temp;

    if (length(frame->a) < 2)
    {
        printf("rrb : 해당 연산을 수행할 수 없습니다.\n");
        return ;
    }
    temp = last_element(frame->b);
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = frame->b;
    frame->b->prev = temp;
    frame->b = temp;
    add_command(frame, "rrb");
    print_stack(frame);
}

void    reverse_rotate_r(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2)
    {
        printf("rrr : 해당 연산을 수행할 수 없습니다.\n");
        return ;
    }
    temp = last_element(frame->a);
    temp->prev->next = NULL;
    temp->next = frame->a;
    frame->a = temp;

    temp = last_element(frame->b);
    temp->prev->next = NULL;
    temp->next = frame->b;
    frame->b = temp;
    
    add_command(frame, "rrr");
    print_stack(frame);
}